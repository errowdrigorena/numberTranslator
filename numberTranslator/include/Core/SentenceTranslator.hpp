/*
 * Number_composition_handler.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_SENTENCE_TRANSLATOR_HPP_
#define INCLUDE_CORE_SSENTENCE_TRANSLATOR_HPP_

#include <string>
#include <vector>
#include <memory>

namespace core
{
enum class Composition_operations
{
	none,
	units,
	decenes,
	hundreds,
	hundred_and,
	thowsands,
	thowsand_and,
	millions,
	million_and,
	billions,
	billion_and
};

class Sentence_translator : public std::enable_shared_from_this<Sentence_translator>
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

	//bool is_composed_;
	std::string composed_number_;

	std::vector<std::string> original_word_sentence_;
	std::vector<std::string> translated_word_sentence_;

	Composition_operations last_operation_;

};

}



#endif /* INCLUDE_CORE_STATEMACHINE_NUMBER_COMPOSITION_HANDLER_HPP_ */