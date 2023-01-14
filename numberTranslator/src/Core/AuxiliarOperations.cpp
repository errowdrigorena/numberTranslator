/*
 * AuxiliarOpertaions.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */
#include <Core/AuxiliarOperations.hpp>
#include <algorithm>

namespace core
{
	std::string convert_to_lowercase(const std::string& word)
	{
		std::string output{};

	    std::transform(word.begin(), word.end(), std::back_inserter(output), ::tolower );

	    return output;
	}
}


