/*
 * AuxiliarOperations.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef SRC_CORE_AUXILIAROPERATIONS_HPP_
#define SRC_CORE_AUXILIAROPERATIONS_HPP_

#include<Core/SentenceTranslationDataModel.hpp>

#include <string>
#include <vector>

namespace core
{
	std::string convert_to_lowercase(const std::string& word);

	std::string read_file(const std::string& fileName);
	void write_file(const std::string& file_name, const std::string& content);

	std::vector<std::string> get_sentences(const std::string& text);

	std::vector<std::string> get_words(const std::string& sentence);

	bool is_hundred(std::string& word);

	bool is_and(std::string& word);

	bool is_thowsand(std::string& word);

	bool is_million(std::string& word);

	bool is_billion(std::string& word);

	bool is_decene_continuable(Composition_operations operation);

	bool is_decene_and(Composition_operations operation);

	bool is_three_zero_multiple_prefix(Composition_operations operation);
}



#endif /* SRC_CORE_AUXILIAROPERATIONS_HPP_ */
