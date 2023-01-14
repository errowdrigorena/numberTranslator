/*
 * Translator.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#include <Core/Translator.hpp>
#include <Core/AuxiliarOperations.hpp>

#include <iostream>

namespace core
{

Translator::Translator(const std::string& inputFileName) : sentences_{}, translated_text_{}
{
	try
	{
		auto file_content = read_file(inputFileName);
		sentences_ = get_sentences(file_content);
	}
	catch(std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

std::string Translator::get_translated_text() const
{
	if(translated_text_)
	{
		return translated_text_;
	}

	//todo: obtain translation
	return translated_text_;
}

}
