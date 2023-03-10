/*
 * Decimal_translation_command.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/DecimalTranslationCommand.hpp>
#include <Core/Utilities/TranslationOperations.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>

namespace core
{
namespace commands
{

void Decimal_translation_command::execute(model_ptr model, std::string word)
{
	auto translated_decimals= utilities::translate_decimals(word);

	if(!utilities::is_decene_continuable(model->last_operation_))
	{
		force_writing_actual_composition(model);
	}

	if(utilities::is_decene_and(model->last_operation_))
	{
		model->composed_number_.erase(model->composed_number_.end()-2,
				model->composed_number_.end());
	}

	model->composed_number_.push_back(translated_decimals);
	model->composed_number_.push_back('0');
	model->last_operation_ = Composition_operations::decenes;
}

} //end commands
} //end core
