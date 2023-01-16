/*
 * MillionTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/MillionTranslationCommand.hpp>

namespace core
{

void Million_translation_command::execute(model_ptr model, std::string word)
{
	model->composed_number_.append("000000");
	model->last_operation_ = Composition_operations::millions;
}

}

