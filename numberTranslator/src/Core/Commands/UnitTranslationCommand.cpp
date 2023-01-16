/*
 * UnitTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */


#include <Core/Commands/UnitTranslationCommand.hpp>
#include <Core/Utilities/TranslationOperations.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>

namespace core
{
namespace commands
{

bool is_unit_composable(model_ptr model);

} //end commands
} //end core

namespace core
{
namespace commands
{

void Unit_translation_command::execute(model_ptr model, std::string word)
{
	auto translated_units = translate_units(word);

	if(!is_unit_composable(model))
	{
		force_writing_actual_composition(model);
	}

	if(model->last_operation_ != Composition_operations::none)
	{
		model->composed_number_.pop_back();
	}

	model->composed_number_.push_back(translated_units);
	model->last_operation_ = Composition_operations::units;
}

bool is_unit_composable(model_ptr model)
{
	auto imposible_to_compose = model->last_operation_ == Composition_operations::decenes
			|| model->last_operation_ == Composition_operations::hundreds
			|| model->last_operation_ == Composition_operations::thowsands
			|| model->last_operation_ == Composition_operations::units
			|| model->last_operation_ == Composition_operations::millions;

	return !imposible_to_compose;
}

} //end commands
} //end core
