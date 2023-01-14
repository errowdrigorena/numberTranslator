/*
 * NonComposable.cpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */
#include<Core/NonComposables.hpp>
#include<Core/AuxiliarOperations.hpp>

#include<unordered_map>

namespace core
{
	int dummyOne()
	{
		return 1;
	}

	char translate_units(const std::string& word)
	{
		static const std::unordered_map<std::string, char> units_to_numerical{
			{"one", '1'},
			{"two", '2'},
			{"three", '3'},
			{"four", '4'},
			{"five", '5'},
			{"six", '6'},
			{"seven", '7'},
			{"eight", '8'},
			{"nine", '9'}
		};

		static const char no_translatable{0 };
		char output = no_translatable;

		auto lowercase_word = convert_to_lowercase(word);
		auto it = units_to_numerical.find(lowercase_word);
		if( it != units_to_numerical.end() )
		{
			output = it->second;
		}

		return output;
	}

}


