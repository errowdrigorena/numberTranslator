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

	std::string read_file(const std::string& fileName)
	{
		std::string file_content{};

		std::ifstream infile(fileName);

		if(!infile.is_open())
		{
			std::cerr<<"Unable to open the file. \n";
			return file_content;
		}

		std::string line;
		while(getline(infile, line))
		{
			std::cout<<line<<std::endl;
			file_content.append(line);
		}

		std::cout<<"FILE CONTENT IS" << std::endl;
		std::cout << file_content << std::endl;

		return file_content;
	}
}


