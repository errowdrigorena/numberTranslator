/*
 * ASentenceTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */
#include<Core/Commands/ASentenceTranslationCommand.hpp>

namespace core
{
namespace commands
{

void ASentence_translation_command::insert_stored_numeric(model_ptr model)
{
	model->translated_word_sentence_.push_back(model->composed_number_);

	model->composed_number_.clear();
}

void ASentence_translation_command::force_writing_actual_composition(model_ptr model)
{
	insert_stored_numeric(model);
	model->last_operation_ = Composition_operations::none;
}

} // end commands
} // end core
