/*
 * Decimal_translation_command.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/DecimalTranslationCommand.hpp>
#include <Core/TranslationOperations.hpp>
#include <Core/AuxiliarOperations.hpp>

namespace core
{

void Decimal_translation_command::execute(model_ptr model, std::string word)
{
	auto translated_decimals= translate_decimals(word);

	if(!is_decene_continuable(model->last_operation_))
	{
		force_writing_actual_composition(model);
	}

	if(is_decene_and(model->last_operation_))
	{
		model->composed_number_.erase(model->composed_number_.end()-2,
				model->composed_number_.end());
	}

	model->composed_number_.push_back(translated_decimals);
	model->composed_number_.push_back('0');
	model->last_operation_ = Composition_operations::decenes;
}

}


