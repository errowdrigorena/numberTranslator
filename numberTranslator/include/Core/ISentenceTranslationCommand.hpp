/*
 * SentenceTranslationCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_ISENTENCETRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_ISENTENCETRANSLATIONCOMMAND_HPP_

#include <Core/SentenceTranslationDataModel.hpp>
#include <memory>

using model_ptr = std::shared_ptr<core::Sentence_translation_data_model>;

namespace core
{

class ISetence_translation_command
{
public:
	virtual ~ISetence_translation_command() = default;

	virtual void execute(model_ptr model) = 0;
};

}



#endif /* INCLUDE_CORE_ISENTENCETRANSLATIONCOMMAND_HPP_ */
