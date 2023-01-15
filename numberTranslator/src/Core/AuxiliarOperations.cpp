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
#include <stdexcept>

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
			throw(std::invalid_argument("Unable to open the file. \n"));
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

	std::vector<std::string> get_words(const std::string& sentence)
	{
		std::vector<std::string> words{};

		auto it_begin_word = std::find_if(sentence.begin(), sentence.end(), [](char input){return ' ' != input;});
		auto it_end_word = std::find_if(it_begin_word, sentence.end(), [](char input){return ' ' == input;});

		while(it_end_word != sentence.end())
		{
			std::string word{it_begin_word, it_end_word};
			words.push_back(word);

			it_begin_word = std::find_if(it_end_word, sentence.end(), [](char input){return ' ' != input;});
			it_end_word = std::find_if(it_begin_word, sentence.end(), [](char input){return ' ' == input;});
		}

		std::string word{it_begin_word, sentence.end()};
		words.push_back(word);

		return words;
	}

	bool is_hundred(std::string& word)
	{
		auto word_lower = convert_to_lowercase(word);
		return "hundred" == word_lower;
	}

	bool is_and(std::string& word)
	{
		auto word_lower = convert_to_lowercase(word);
		return "and" == word_lower;
	}

	bool is_thowsand(std::string& word)
	{
		auto word_lower = convert_to_lowercase(word);
		return "thowsand" == word_lower;
	}

	bool is_million(std::string& word)
	{
		auto word_lower = convert_to_lowercase(word);
		return "million" == word_lower;
	}

	bool is_billion(std::string& word)
	{
		auto word_lower = convert_to_lowercase(word);
		return "billion" == word_lower;
	}
}


