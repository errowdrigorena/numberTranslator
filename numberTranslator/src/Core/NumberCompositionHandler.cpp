/*
 * NumberCompositionHandler.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */
#include <Core/NumberCompositionHandler.hpp>
#include <Core/AuxiliarOperations.hpp>
#include <Core/TranslationOperations.hpp>
#include <algorithm>
#include <iostream> //delete

namespace core
{

Number_composition_handler::Number_composition_handler(std::vector<std::string> word_sentence) : composed_number_{},
		word_sentence_{word_sentence}, last_operation_{Composition_operations::none}
{

}

void Number_composition_handler::compose_sentence()
{
  for(auto& word : word_sentence_)
  {
	  compose_number(word);
  }
}

void Number_composition_handler::compose_number(std::string word)
{
	auto it_guidon = std::find(word.begin(), word.end(), '-');

	if( it_guidon != word.end() )
	{
		std::string first_half{word.begin(), it_guidon};
		std::cout << first_half << std::endl;
		auto translated_first_half = translate_decimals(first_half);
		std::cout << translated_first_half << std::endl;

		if(translated_first_half)
		{
			std::string second_half{it_guidon+1, word.end()};
			std::cout << second_half << std::endl;
			auto translated_second_half = translate_units(second_half);
			std::cout << translated_second_half << std::endl;
			if(translated_second_half)
			{
				if(last_operation_ == Composition_operations::units || last_operation_ == Composition_operations::hundreds)
				{
					//clean operation
					std::cout << "Previously units or hundreds" << std::endl;

					auto it = std::find(word_sentence_.begin(), word_sentence_.end(), word);
					replace_for_numerics(it);
					last_operation_ = Composition_operations::none; //call this operation again
				}

				if(last_operation_ == Composition_operations::none)
				{
					first_word_to_delete_ = word;
				}

				if(last_operation_ == Composition_operations::hundred_and)
				{
					composed_number_.erase(composed_number_.end()-2, composed_number_.end());
				}

				std::cout << "The first word to delete is NOW: " << first_word_to_delete_ << std::endl;
				composed_number_.push_back(translated_first_half);
				composed_number_.push_back(translated_second_half);

				last_operation_ = Composition_operations::decenes;
			}
		}

		return;
	}

	auto translated_units = translate_units(word);

	if(translated_units)
	{
		std::cout << "Translate units " << translated_units << std::endl;

		if(last_operation_ == Composition_operations::decenes || last_operation_ == Composition_operations::hundreds)
		{
			std::cout << "Previously decenes" << std::endl;

			auto it = std::find(word_sentence_.begin(), word_sentence_.end(), word);
			replace_for_numerics(it);
			last_operation_ = Composition_operations::none;
		}

		if(last_operation_ == Composition_operations::none)
		{
			first_word_to_delete_ = word;
		}
		else
		{
			composed_number_.pop_back();
		}

		composed_number_.push_back(translated_units);
		last_operation_ = Composition_operations::units;

		std::cout << "WORDS WE HAVE" << std::endl;
		for(auto word : word_sentence_)
		{
			std::cout << word << std::endl;
		}

		return;
	}

	auto translated_decimals= translate_decimals(word);

	if(translated_decimals)
	{
		if(last_operation_ == Composition_operations::units || last_operation_ == Composition_operations::hundreds)
		{
			//clean operation
			std::cout << "Previously units or hundreds" << std::endl;

			auto it = std::find(word_sentence_.begin(), word_sentence_.end(), word);
			replace_for_numerics(it);
			last_operation_ = Composition_operations::none; //call this operation again
		}

		if(last_operation_ == Composition_operations::none)
		{
			first_word_to_delete_ = word;
			std::cout << "The first word to delete is NOW: " << first_word_to_delete_ << std::endl;

		}

		if(last_operation_ == Composition_operations::hundred_and)
		{
			composed_number_.erase(composed_number_.end()-2, composed_number_.end());
		}

		composed_number_.push_back(translated_decimals);
		composed_number_.push_back('0');
		last_operation_ = Composition_operations::decenes;

		return;
	}

	auto translated_teens = translate_teens(word);

	if(!translated_teens.empty()) //funciona como decimals si se le pasa una cadena a estos
	{
		std::cout << translated_teens << std::endl;
		if(last_operation_ == Composition_operations::units || last_operation_ == Composition_operations::hundreds)
		{
			//clean operation
			std::cout << "Previously units or hundreds" << std::endl;

			auto it = std::find(word_sentence_.begin(), word_sentence_.end(), word);
			replace_for_numerics(it);
			last_operation_ = Composition_operations::none; //call this operation again
		}

		if(last_operation_ == Composition_operations::none)
		{
			first_word_to_delete_ = word;
			std::cout << "The first word to delete is NOW: " << first_word_to_delete_ << std::endl;

		}

		if(last_operation_ == Composition_operations::hundred_and)
		{
			composed_number_.erase(composed_number_.end()-2, composed_number_.end());
		}

		composed_number_.append(translated_teens);

		last_operation_ = Composition_operations::decenes;
		return;
	}

	if(is_hundred(word))
	{
		if(last_operation_ == Composition_operations::units)
		{
			composed_number_.append("00");
			last_operation_ = Composition_operations::hundreds;
			return;
		}
	}

	if(is_and(word))
	{
		if(last_operation_ == Composition_operations::hundreds)
		{
			last_operation_ = Composition_operations::hundred_and;
			return;
		}
	}

	if(composed_number_.empty())
	{
		return;
	}

	auto it = std::find(word_sentence_.begin(), word_sentence_.end(), word);
	replace_for_numerics(it);
}

bool Number_composition_handler::is_composed() const
{
	return false;
}

void Number_composition_handler::replace_for_numerics(std::vector<std::string>::iterator it_last_number_word)
{
	std::cout << "The first word to delete is: " << first_word_to_delete_ << std::endl;
	std::cout << "The first composed number: " << composed_number_ << std::endl;

	auto it_number_begin = std::find(word_sentence_.begin(), word_sentence_.end(), first_word_to_delete_);
	*it_number_begin = composed_number_;

	composed_number_.clear();
	first_word_to_delete_.clear();

	word_sentence_.erase(it_number_begin+1, it_last_number_word);
}

void Number_composition_handler::force_last_numerics()
{
	if(first_word_to_delete_.empty())
	{
		std::cout << "The first word to delete is EMPTY " << std::endl;
		return;
	}

	replace_for_numerics(word_sentence_.end());
}

std::string Number_composition_handler::get_sentence_with_numbers()
{
	std::string sentence{};

	compose_sentence();
	force_last_numerics();

	for(auto& word : word_sentence_)
	{
		sentence.append(word);
		sentence.append(" ");
	}

	sentence.back() = '.';

	return sentence;
}


}


