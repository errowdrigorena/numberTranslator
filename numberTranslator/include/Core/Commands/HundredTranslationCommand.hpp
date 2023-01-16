/*
 * HundredTranslationCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_HUNDREDTRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_HUNDREDTRANSLATIONCOMMAND_HPP_

#include "ASentenceTranslationCommand.hpp"

namespace core
{

class Hundred_translation_command: public ASentence_translation_command
{
public:
	virtual ~Hundred_translation_command() = default;

	void execute(model_ptr model, std::string word) override;
};

}

#endif /* INCLUDE_CORE_HUNDREDTRANSLATIONCOMMAND_HPP_ */
