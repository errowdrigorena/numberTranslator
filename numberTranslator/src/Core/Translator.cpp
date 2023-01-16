/*
 * Translator.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#include <Core/Translator.hpp>
#include <Core/Utilities/AuxiliarOperations.hpp>
#include <Core/SentenceTranslator.hpp>

#include <iostream>

namespace core
{

Translator::Translator(const std::string& inputFileName) : sentences_{}, translated_text_{}
{
	try
	{
		auto file_content = utilities::read_file(inputFileName);
		sentences_ = utilities::get_sentences(file_content);
	}
	catch(std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

std::string Translator::get_translated_text()
{
	if(!translated_text_.empty())
	{
		return translated_text_;
	}

	//todo: obtain translation
	for(auto& sentence : sentences_)
	{
		auto word_divided_sentence = utilities::get_words(sentence);
		Sentence_translator sentence_translator{word_divided_sentence};

		auto translated_sentence = sentence_translator.get_sentence_with_numbers();
		translated_text_.append(translated_sentence);
		translated_text_.push_back('\n');
	}

	return translated_text_;
}

}
