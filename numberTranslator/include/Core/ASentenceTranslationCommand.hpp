/*
 * SentenceTranslationCommand.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_ASENTENCETRANSLATIONCOMMAND_HPP_
#define INCLUDE_CORE_ASENTENCETRANSLATIONCOMMAND_HPP_

#include <Core/SentenceTranslationDataModel.hpp>
#include <memory>
#include <string>

using model_ptr = std::shared_ptr<core::Sentence_translation_data_model>;

namespace core
{

class ASentence_translation_command
{
public:
	virtual ~ASentence_translation_command() = default;

	virtual void execute(model_ptr model, std::string word) = 0;

	void insert_stored_numeric(model_ptr model);
	void force_writing_actual_composition(model_ptr model);
};

}



#endif /* INCLUDE_CORE_ASENTENCETRANSLATIONCOMMAND_HPP_ */
