/*
 * ThowsandTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/ThowsandTranslationCommand.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>

namespace core
{
namespace commands
{

void Thowsand_translation_command::execute(model_ptr model, std::string word)
{
	if(model->composed_number_.size() > 6)
	{
		model->composed_number_.erase(model->composed_number_.end()-6,
				model->composed_number_.end()-3);
	}

	model->composed_number_.append("000");
	model->last_operation_ = Composition_operations::thowsands;
}

} //end commands
} //end core
