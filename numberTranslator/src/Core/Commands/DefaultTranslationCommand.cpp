/*
 * DefaultTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#include <Core/Commands/DefaultTranslationCommand.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>

namespace core
{
namespace commands
{

void Default_translation_command::execute(model_ptr model, std::string word)
{
	bool is_insert_and{false };

	if(is_decene_and(model->last_operation_)) //supports every and
	{
		is_insert_and = true;
	}

	if(model->composed_number_.empty())
	{
		if(is_insert_and)
		{
			model->translated_word_sentence_.push_back("and");
		}

		model->translated_word_sentence_.push_back(word);
		return;
	}

	insert_stored_numeric(model);

	if(is_insert_and)
	{
		model->translated_word_sentence_.push_back("and");
	}

	model->translated_word_sentence_.push_back(word);
}

} //end commands
} //end core


