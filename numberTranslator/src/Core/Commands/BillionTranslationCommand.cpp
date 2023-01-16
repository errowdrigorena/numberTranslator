/*
 * BillionTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/BillionTranslationCommand.hpp>

namespace core
{

void Billion_translation_command::execute(model_ptr model, std::string word)
{
	model->composed_number_.append("000000000");
	model->last_operation_ = Composition_operations::billions;
}

}


