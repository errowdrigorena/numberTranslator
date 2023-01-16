/*
 * HundredTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/HundredTranslationCommand.hpp>

namespace core
{

void Hundred_translation_command::execute(model_ptr model, std::string word)
{
	if(model->composed_number_.size() > 2)
	{
		model->composed_number_.erase(model->composed_number_.end()-3,
				model->composed_number_.end()-1);
	}

	model->composed_number_.append("00");
	model->last_operation_ = Composition_operations::hundreds;
}

}


