/*
 * NonComposables.hpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_TRANSLATIONOPERATIONS_HPP_
#define INCLUDE_CORE_TRANSLATIONOPERATIONS_HPP_

#include <string>

namespace core
{
	//output is an ASCII code number for (1-9). 0 if senseless translation
	char translate_units(const std::string& word);

	//output is an ASCII code number for (10-19). Empty if senseless translation
	std::string translate_teens(const std::string& word);

	//output is an ASCII code number for (2-9) (20 -> 2, 30 -> 3 ...). 0 if senseless translation
	char translate_decimals(const std::string& word);
}

#endif /* INCLUDE_CORE_TRANSLATIONOPERATIONS_HPP_ */
