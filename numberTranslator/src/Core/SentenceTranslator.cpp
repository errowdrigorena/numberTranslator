/*
 * NumberCompositionHandler.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */
#include <Core/SentenceTranslator.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>
#include <Core/Utilities/TranslationOperations.hpp>

#include <Core/Commands/GuidonDecimalTranslationCommand.hpp>
#include <Core/Commands/DecimalTranslationCommand.hpp>
#include <Core/Commands/UnitTranslationCommand.hpp>
#include <Core/Commands/TeensTranslationCommand.hpp>
#include <Core/Commands/HundredTranslationCommand.hpp>
#include <Core/Commands/ThowsandTranslationCommand.hpp>
#include <Core/Commands/MillionTranslationCommand.hpp>
#include <Core/Commands/BillionTranslationCommand.hpp>
#include <Core/Commands/DefaultTranslationCommand.hpp>

#include <algorithm>

namespace core
{

Sentence_translator::Sentence_translator(std::vector<std::string> word_sentence) :
		translation_model_{std::make_shared<Sentence_translation_data_model>()}
{
	translation_model_->last_operation_ = Composition_operations::none;
	translation_model_->original_word_sentence_ = word_sentence;
}

void Sentence_translator::compose_sentence()
{
  for(auto& word : translation_model_->original_word_sentence_)
  {
	  compose_number(word);
  }
}

void Sentence_translator::compose_number(std::string word)
{
	auto it_guidon = std::find(word.begin(), word.end(), '-');

	if( it_guidon != word.end() )
	{
		commands::Guidon_decimal_translation_command guidon_translator{};
		guidon_translator.execute(translation_model_, word);

		return;
	}

	auto translated_units = translate_units(word);

	if(translated_units)
	{
		commands::Unit_translation_command unit_translator{};
		unit_translator.execute(translation_model_, word);

		return;
	}

	auto translated_decimals= translate_decimals(word);

	if(translated_decimals)
	{
		commands::Decimal_translation_command decimal_translator{};
		decimal_translator.execute(translation_model_, word);

		return;
	}

	auto translated_teens = translate_teens(word);

	if(!translated_teens.empty())
	{
		commands::Teens_translation_command teens_translator{};
		teens_translator.execute(translation_model_, word);

		return;
	}

	if(is_hundred(word))
	{
		if(translation_model_->last_operation_ == Composition_operations::units)
		{
			commands::Hundred_translation_command hundred_translator{};
			hundred_translator.execute(translation_model_, word);

			return;
		}
	}

	if(is_thowsand(word))
	{
		if(is_three_zero_multiple_prefix(translation_model_->last_operation_))
		{
			commands::Thowsand_translation_command thowsand_translator{};
			thowsand_translator.execute(translation_model_, word);

			return;
		}
	}

	if(is_million(word))
	{
		if( is_three_zero_multiple_prefix(translation_model_->last_operation_) )
		{
			commands::Million_translation_command million_translator{};
			million_translator.execute(translation_model_, word);

			return;
		}
	}

	if(is_billion(word))
	{
		if( translation_model_->last_operation_ == Composition_operations::units )
		{
			commands::Billion_translation_command billion_translator{};
			billion_translator.execute(translation_model_, word);

			return;
		}
	}

	if(is_and(word))
	{
		if(translation_model_->last_operation_ == Composition_operations::hundreds)
		{
			translation_model_->last_operation_ = Composition_operations::hundred_and;
			return;
		}
		if(translation_model_->last_operation_ == Composition_operations::thowsands)
		{
			translation_model_->last_operation_ = Composition_operations::thowsand_and;
			return;
		}
		if(translation_model_->last_operation_ == Composition_operations::millions)
		{
			translation_model_->last_operation_ = Composition_operations::million_and;
			return;
		}
	}

	commands::Default_translation_command default_translator{};
	default_translator.execute(translation_model_, word);
}

void Sentence_translator::insert_stored_numeric()
{
	translation_model_->translated_word_sentence_.push_back(translation_model_->composed_number_);

	translation_model_->composed_number_.clear();
}

void Sentence_translator::force_last_numerics()
{
	if(translation_model_->composed_number_.empty())
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

	for(auto& word : translation_model_->translated_word_sentence_)
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


