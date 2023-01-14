/*
 * NonComposables.hpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_NONCOMPOSABLES_HPP_
#define INCLUDE_CORE_NONCOMPOSABLES_HPP_

#include <string>

namespace core
{
	int dummyOne();

	//output is an ASCII code number. 0 if senseless translation
	char translate_units(const std::string& word);
}

#endif /* INCLUDE_CORE_NONCOMPOSABLES_HPP_ */
