/*
 * TeensTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/TeensTranslationCommand.hpp>
#include <Core/TranslationOperations.hpp>
#include <Core/AuxiliarOperations.hpp>

namespace core
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

}


