/*
 * Number_composition_handler.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_STATEMACHINE_NUMBER_COMPOSITION_HANDLER_HPP_
#define INCLUDE_CORE_STATEMACHINE_NUMBER_COMPOSITION_HANDLER_HPP_

#include <string>
#include <vector>

namespace core
{
class Number_composition_handler
{
public:
	Number_composition_handler(std::vector<std::string> word_sentence);

	void compose_number(std::string);

	bool is_composed() const;

	std::string get_sentence_with_numbers();

	void compose_sentence();
private:
	void force_last_numerics();
	void replace_for_numerics(std::vector<std::string>::iterator it_last_number_word);

	//bool is_composed_;
	std::string composed_number_;

	std::vector<std::string> word_sentence_;
	std::string first_word_to_delete_;

};

}



#endif /* INCLUDE_CORE_STATEMACHINE_NUMBER_COMPOSITION_HANDLER_HPP_ */
