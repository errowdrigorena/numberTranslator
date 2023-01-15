/*
 * Number_composition_handler.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_SENTENCE_TRANSLATOR_HPP_
#define INCLUDE_CORE_SSENTENCE_TRANSLATOR_HPP_

#include <Core/SentenceTranslationDataModel.hpp>
#include <string>
#include <vector>
#include <memory>

namespace core
{

class Sentence_translator
{
public:
	Sentence_translator(std::vector<std::string> word_sentence);

	std::string get_sentence_with_numbers();
private:
	void force_last_numerics();
	void insert_stored_numeric();
	void compose_number(std::string word);
	void compose_sentence();

	std::shared_ptr<Sentence_translation_data_model> translation_model_;
};

}



#endif /* INCLUDE_CORE_STATEMACHINE_NUMBER_COMPOSITION_HANDLER_HPP_ */
