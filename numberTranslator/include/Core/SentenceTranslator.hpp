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

	void compose_number(std::string number);

	bool is_composed() const;

	std::string get_sentence_with_numbers();

	void compose_sentence();
private:
	void force_last_numerics();
	void insert_stored_numeric();
	void force_writing_actual_composition();

	std::shared_ptr<Sentence_translation_data_model> translation_model_;
};

}



#endif /* INCLUDE_CORE_STATEMACHINE_NUMBER_COMPOSITION_HANDLER_HPP_ */
