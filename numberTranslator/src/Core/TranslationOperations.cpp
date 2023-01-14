/*
 * NonComposable.cpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */
#include<Core/AuxiliarOperations.hpp>
#include <Core/TranslationOperations.hpp>

#include<unordered_map>

namespace core
{
	template<typename T>
	T translate(const std::string& key, const std::unordered_map<std::string, T> dictionary);
}

namespace core
{
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

		return translate(word, units_to_numerical);
	}

	template<typename T>
	T translate(const std::string& key, const std::unordered_map<std::string, T> dictionary)
	{
		T no_translatable{};
		T output = no_translatable;

		auto lowercase_key = convert_to_lowercase(key);
		auto it = dictionary.find(lowercase_key);
		if( it != dictionary.end() )
		{
			output = it->second;
		}

		return output;
	}

	std::string translate_teens(const std::string& word)
	{
		static const std::unordered_map<std::string, std::string> teens_to_numerical{
			{"ten", "10"},
			{"eleven", "11"},
			{"twelve", "12"},
			{"thirteen", "13"},
			{"fourteen", "14"},
			{"fifteen", "15"},
			{"sixteen", "16"},
			{"seventeen", "17"},
			{"eighteen", "18"},
			{"nineteen", "19"}
		};

		return translate(word, teens_to_numerical);
	}

	char translate_decimals(const std::string& word)
	{
		static const std::unordered_map<std::string, char> decimals_to_numerical{
			{"twenty", '2'},
			{"thirty", '3'},
			{"forty", '4'},
			{"fifty", '5'},
			{"sixty", '6'},
			{"seventy", '7'},
			{"eighty", '8'},
			{"ninety", '9'}
		};

		return translate(word, decimals_to_numerical);
	}

}


