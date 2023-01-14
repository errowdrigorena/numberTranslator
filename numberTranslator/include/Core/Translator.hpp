/*
 * Translator.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_TRANSLATOR_HPP_
#define INCLUDE_CORE_TRANSLATOR_HPP_

#include <string>
#include <vector>

namespace core
{

class Translator
{
public:
	explicit Translator(const std::string& inputFileName);

	std::string get_translated_text() const;

private:
	std::vector<std::string> sentences_;
	std::string translated_text_;
};

}

#endif /* INCLUDE_CORE_TRANSLATOR_HPP_ */
