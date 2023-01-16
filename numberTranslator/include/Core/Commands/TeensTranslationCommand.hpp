/*
 * TeensTranslationCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_TEENSTRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_TEENSTRANSLATIONCOMMAND_HPP_

#include "ASentenceTranslationCommand.hpp"

namespace core
{
namespace commands
{

class Teens_translation_command: public ASentence_translation_command
{
public:
	virtual ~Teens_translation_command() = default;

	void execute(model_ptr model, std::string word) override;
};

} // end commands
} // end core

#endif /* INCLUDE_CORE_TEENSTRANSLATIONCOMMAND_HPP_ */
