/*
 * GuidonDecimalTranslationCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_GUIDONDECIMALTRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_GUIDONDECIMALTRANSLATIONCOMMAND_HPP_

#include "ASentenceTranslationCommand.hpp"

namespace core
{
namespace commands
{

class Guidon_decimal_translation_command: public ASentence_translation_command
{
public:
	virtual ~Guidon_decimal_translation_command() = default;

	void execute(model_ptr model, std::string word) override;
};

} // end commands
} // end core



#endif /* INCLUDE_CORE_GUIDONDECIMALTRANSLATIONCOMMAND_HPP_ */
