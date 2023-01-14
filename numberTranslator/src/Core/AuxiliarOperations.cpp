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

	std::vector<std::string> read_file_line_by_line(const std::string& fileName)
	{
		std::vector<std::string> file_lines{};

		std::ifstream infile(fileName);

		if(!infile.is_open())
		{
			std::cerr<<"Unable to open the file. \n";
			return file_lines;
		}

		return file_lines;
	}
}


