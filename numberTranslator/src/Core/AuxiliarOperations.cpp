/*
 * AuxiliarOpertaions.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */
#include <Core/AuxiliarOperations.hpp>
#include <algorithm>
#include <fstream>
#include <iostream>

namespace core
{
	std::string convert_to_lowercase(const std::string& word)
	{
		std::string lowercase_word{};

	    std::transform(word.begin(), word.end(), std::back_inserter(lowercase_word), ::tolower );

	    return lowercase_word;
	}

	std::string read_file(const std::string& fileName) noexcept(false)
	{
		std::string file_content{};

		std::ifstream infile(fileName);

		if(!infile.is_open())
		{
			throw("Unable to open the file. \n");
			return file_content;
		}

		std::string line;
		while(getline(infile, line))
		{
			file_content.append(line);
		}

		return file_content;
	}

	std::vector<std::string> get_sentences(const std::string& text)
	{
		std::vector<std::string> sentences{};
		const char period_character{'.'};

		auto it_begin_position = text.begin();
		auto period_position = std::find(it_begin_position, text.end(),period_character);

		while(period_position != text.end())
		{
			std::string sentence{it_begin_position, period_position};
			sentences.push_back(sentence);

			it_begin_position = std::find_if(period_position + 1, text.end(), [](char input){return ' ' != input;});
			period_position = std::find(it_begin_position, text.end(),period_character);
		}


		return sentences;
	}
}


