/*
 * GuidonDecimalTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/GuidonDecimalTranslationCommand.hpp>
#include <Core/Utilities/TranslationOperations.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>

#include <algorithm>

namespace core
{
namespace commands
{

void Guidon_decimal_translation_command::execute(model_ptr model, std::string word)
{
	auto it_guidon = std::find(word.begin(), word.end(), '-');

	if( it_guidon != word.end() )
	{
		std::string first_half{word.begin(), it_guidon};
		auto translated_first_half = utilities::translate_decimals(first_half);

		if(translated_first_half)
		{
			std::string second_half{it_guidon+1, word.end()};
			auto translated_second_half = utilities::translate_units(second_half);

			if(translated_second_half)
			{
				if(!utilities::is_decene_continuable(model->last_operation_))
				{
					force_writing_actual_composition(model);
				}


				if(utilities::is_decene_and(model->last_operation_))
				{
					model->composed_number_.erase(model->composed_number_.end()-2,
							model->composed_number_.end());
				}


				model->composed_number_.push_back(translated_first_half);
				model->composed_number_.push_back(translated_second_half);

				model->last_operation_ = Composition_operations::decenes;
			}
		}
		else
		{
			model->translated_word_sentence_.push_back(word);
		}

	}
} //end commands
} //end core

};

