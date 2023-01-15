/*
 * NumberCompositionHandler.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */
#include "../../include/Core/SentenceTranslator.hpp"

#include <Core/AuxiliarOperations.hpp>
#include <Core/TranslationOperations.hpp>
#include <algorithm>
#include <iostream> //delete

namespace core
{
	bool is_decene_continuable(Composition_operations operation);
	bool is_decene_and(Composition_operations operation);
	bool is_three_zero_multiple_prefix(Composition_operations operation);
}
namespace core
{

Sentence_translator::Sentence_translator(std::vector<std::string> word_sentence) : translation_model_{}
{
	translation_model_.last_operation_ = Composition_operations::none;
	translation_model_.original_word_sentence_ = word_sentence;
}

void Sentence_translator::compose_sentence()
{
  for(auto& word : translation_model_.original_word_sentence_)
  {
	  compose_number(word);
  }
}

void Sentence_translator::compose_number(std::string word)
{
	auto it_guidon = std::find(word.begin(), word.end(), '-');

	if( it_guidon != word.end() )
	{
		std::string first_half{word.begin(), it_guidon};
		auto translated_first_half = translate_decimals(first_half);

		if(translated_first_half)
		{
			std::string second_half{it_guidon+1, word.end()};
			auto translated_second_half = translate_units(second_half);

			if(translated_second_half)
			{
				if(!is_decene_continuable(translation_model_.last_operation_))
				{
					force_writing_actual_composition();
				}


				if(is_decene_and(translation_model_.last_operation_))
				{
					translation_model_.composed_number_.erase(translation_model_.composed_number_.end()-2,
							translation_model_.composed_number_.end());
				}


				translation_model_.composed_number_.push_back(translated_first_half);
				translation_model_.composed_number_.push_back(translated_second_half);

				translation_model_.last_operation_ = Composition_operations::decenes;
			}
		}
		else
		{
			translation_model_.translated_word_sentence_.push_back(word);
		}

		return;
	}

	auto translated_units = translate_units(word);

	if(translated_units)
	{
		if(translation_model_.last_operation_ == Composition_operations::decenes
				|| translation_model_.last_operation_ == Composition_operations::hundreds
				|| translation_model_.last_operation_ == Composition_operations::thowsands
				|| translation_model_.last_operation_ == Composition_operations::units
				|| translation_model_.last_operation_ == Composition_operations::millions)
		{
			force_writing_actual_composition();
		}

		if(translation_model_.last_operation_ != Composition_operations::none)
		{
			translation_model_.composed_number_.pop_back();
		}

		translation_model_.composed_number_.push_back(translated_units);
		translation_model_.last_operation_ = Composition_operations::units;

		return;
	}

	auto translated_decimals= translate_decimals(word);

	if(translated_decimals)
	{
		if(!is_decene_continuable(translation_model_.last_operation_))
		{
			force_writing_actual_composition();
		}

		if(is_decene_and(translation_model_.last_operation_))
		{
			translation_model_.composed_number_.erase(translation_model_.composed_number_.end()-2,
					translation_model_.composed_number_.end());
		}

		translation_model_.composed_number_.push_back(translated_decimals);
		translation_model_.composed_number_.push_back('0');
		translation_model_.last_operation_ = Composition_operations::decenes;

		return;
	}

	auto translated_teens = translate_teens(word);

	if(!translated_teens.empty()) //funciona como decimals si se le pasa una cadena a estos
	{
		if(!is_decene_continuable(translation_model_.last_operation_))
		{
			force_writing_actual_composition();
		}

		if(is_decene_and(translation_model_.last_operation_))
		{
			translation_model_.composed_number_.erase(translation_model_.composed_number_.end()-2,
					translation_model_.composed_number_.end());
		}

		translation_model_.composed_number_.append(translated_teens);

		translation_model_.last_operation_ = Composition_operations::decenes;
		return;
	}

	if(is_hundred(word))
	{
		if(translation_model_.last_operation_ == Composition_operations::units)
		{
			if(translation_model_.composed_number_.size() > 2)
			{
				translation_model_.composed_number_.erase(translation_model_.composed_number_.end()-3,
						translation_model_.composed_number_.end()-1);
			}

			translation_model_.composed_number_.append("00");
			translation_model_.last_operation_ = Composition_operations::hundreds;
			return;
		}
	}

	if(is_thowsand(word))
	{
		if(translation_model_.composed_number_.size() > 6)
		{
			translation_model_.composed_number_.erase(translation_model_.composed_number_.end()-6,
					translation_model_.composed_number_.end()-3);
		}

		if( is_three_zero_multiple_prefix(translation_model_.last_operation_) )
		{
			translation_model_.composed_number_.append("000");
			translation_model_.last_operation_ = Composition_operations::thowsands;
			return;
		}
	}

	if(is_million(word))
	{
		if( is_three_zero_multiple_prefix(translation_model_.last_operation_) )
		{
			translation_model_.composed_number_.append("000000");
			translation_model_.last_operation_ = Composition_operations::millions;
			return;
		}
	}

	if(is_billion(word))
	{
		if( translation_model_.last_operation_ == Composition_operations::units )
		{
			translation_model_.composed_number_.append("000000000");
			translation_model_.last_operation_ = Composition_operations::billions;
			return;
		}
	}

	if(is_and(word))
	{
		if(translation_model_.last_operation_ == Composition_operations::hundreds)
		{
			translation_model_.last_operation_ = Composition_operations::hundred_and;
			return;
		}
		if(translation_model_.last_operation_ == Composition_operations::thowsands)
		{
			translation_model_.last_operation_ = Composition_operations::thowsand_and;
			return;
		}
		if(translation_model_.last_operation_ == Composition_operations::millions)
		{
			translation_model_.last_operation_ = Composition_operations::million_and;
			return;
		}
	}

	bool is_insert_and{false };

	if(is_decene_and(translation_model_.last_operation_)) //supports every and
	{
		is_insert_and = true;
	}

	if(translation_model_.composed_number_.empty())
	{
		if(is_insert_and)
		{
			translation_model_.translated_word_sentence_.push_back("and");
		}

		translation_model_.translated_word_sentence_.push_back(word);
		return;
	}

	insert_stored_numeric();

	if(is_insert_and)
	{
		translation_model_.translated_word_sentence_.push_back("and");
	}

	translation_model_.translated_word_sentence_.push_back(word);
}

bool is_decene_continuable(Composition_operations operation)
{
	bool is_not_decene_continuable = operation == Composition_operations::units
					|| operation == Composition_operations::hundreds
					|| operation == Composition_operations::decenes
					|| operation == Composition_operations::thowsands
					|| operation == Composition_operations::millions
					|| operation == Composition_operations::billions;

	return !is_not_decene_continuable;
}

bool is_decene_and(Composition_operations operation)
{
	bool is_decene_and = operation == Composition_operations::hundred_and
			|| operation == Composition_operations::thowsand_and
			|| operation == Composition_operations::million_and;

	return is_decene_and;
}

bool is_three_zero_multiple_prefix(Composition_operations operation)
{
	bool is_thowsand_prefix = operation == Composition_operations::units
			|| operation == Composition_operations::decenes
			|| operation == Composition_operations::hundreds;

	return is_thowsand_prefix;
}

void Sentence_translator::force_writing_actual_composition()
{
	insert_stored_numeric();
	translation_model_.last_operation_ = Composition_operations::none;
}

bool Sentence_translator::is_composed() const
{
	return false;
}

void Sentence_translator::insert_stored_numeric()
{
	translation_model_.translated_word_sentence_.push_back(translation_model_.composed_number_);

	translation_model_.composed_number_.clear();
}

void Sentence_translator::force_last_numerics()
{
	if(translation_model_.composed_number_.empty())
	{
		return;
	}

	insert_stored_numeric();
}

std::string Sentence_translator::get_sentence_with_numbers()
{
	std::string sentence{};

	compose_sentence();
	force_last_numerics();

	for(auto& word : translation_model_.translated_word_sentence_)
	{
		sentence.append(word);
		if( !word.empty() )
		{
			sentence.append(" ");
		}
	}

	sentence.back() = '.';


	return sentence;
}


}


