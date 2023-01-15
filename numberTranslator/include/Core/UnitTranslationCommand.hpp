/*
 * UnitTranslationCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_UNITTRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_UNITTRANSLATIONCOMMAND_HPP_

#include "ASentenceTranslationCommand.hpp"

namespace core
{

class Unit_translation_command: public ASentence_translation_command
{
public:
	virtual ~Unit_translation_command() = default;

	void execute(model_ptr model, std::string word) override;
};

}




#endif /* INCLUDE_CORE_UNITTRANSLATIONCOMMAND_HPP_ */
