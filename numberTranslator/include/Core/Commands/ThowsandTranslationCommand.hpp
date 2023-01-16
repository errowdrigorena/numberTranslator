/*
 * ThowsandTranslationCommand.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_THOWSANDTRANSLATIONCOMMAND_CPP_
#define INCLUDE_CORE_THOWSANDTRANSLATIONCOMMAND_CPP_

#include "ASentenceTranslationCommand.hpp"

namespace core
{

class Thowsand_translation_command: public ASentence_translation_command
{
public:
	virtual ~Thowsand_translation_command() = default;

	void execute(model_ptr model, std::string word) override;
};

}

#endif /* INCLUDE_CORE_THOWSANDTRANSLATIONCOMMAND_CPP_ */
