/*
 * BillionTranslatorCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_BILLIONTRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_BILLIONTRANSLATIONCOMMAND_HPP_

#include "ASentenceTranslationCommand.hpp"

namespace core
{
namespace commands
{

class Billion_translation_command: public ASentence_translation_command
{
public:
	virtual ~Billion_translation_command() = default;

	void execute(model_ptr model, std::string word) override;
};

} // end commands
} // end core



#endif /* INCLUDE_CORE_BILLIONTRANSLATIONCOMMAND_HPP_ */
