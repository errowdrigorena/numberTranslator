/*
 * AuxiliarOperations.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef SRC_CORE_AUXILIAROPERATIONS_HPP_
#define SRC_CORE_AUXILIAROPERATIONS_HPP_

#include <string>
#include <vector>

namespace core
{
	std::string convert_to_lowercase(const std::string& word);

	std::string read_file(const std::string& fileName);

	std::vector<std::string> get_sentences(const std::string& text);

	std::vector<std::string> get_words(const std::string& sentence);

	bool is_hundred(std::string& word);

	bool is_and(std::string& word);
}



#endif /* SRC_CORE_AUXILIAROPERATIONS_HPP_ */
