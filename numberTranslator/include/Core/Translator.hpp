/*
 * Translator.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_TRANSLATOR_HPP_
#define INCLUDE_CORE_TRANSLATOR_HPP_

#include <string>

namespace core
{

class Translator
{
public:
	explicit Translator(std::string inputFileName, std::string outputFileName={});
};

}

#endif /* INCLUDE_CORE_TRANSLATOR_HPP_ */
