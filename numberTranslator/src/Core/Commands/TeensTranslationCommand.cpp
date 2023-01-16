/*
 * TeensTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/TeensTranslationCommand.hpp>
#include <Core/Utilities/TranslationOperations.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>

namespace core
{
namespace commands
{

void Teens_translation_command::execute(model_ptr model, std::string word)
{
	auto translated_teens = translate_teens(word);

	if(!is_decene_continuable(model->last_operation_))
	{
		force_writing_actual_composition(model);
	}

	if(is_decene_and(model->last_operation_))
	{
		model->composed_number_.erase(model->composed_number_.end()-2,
				model->composed_number_.end());
	}

	model->composed_number_.append(translated_teens);

	model->last_operation_ = Composition_operations::decenes;
}

} //end commands
} //end core
