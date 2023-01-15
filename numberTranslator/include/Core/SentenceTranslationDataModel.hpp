/*
 * SentenceTranslationDataModel.hpp
 *
 *  Created on: Jan 15, 2023
 *      Author: iban
 */

#ifndef INCLUDE_CORE_SENTENCETRANSLATIONDATAMODEL_HPP_
#define INCLUDE_CORE_SENTENCETRANSLATIONDATAMODEL_HPP_

#include <string>
#include <vector>

namespace core
{

enum class Composition_operations
{
	none,
	units,
	decenes,
	hundreds,
	hundred_and,
	thowsands,
	thowsand_and,
	millions,
	million_and,
	billions,
	billion_and
};

struct Sentence_translation_data_model
{
	std::string composed_number_;

	std::vector<std::string> original_word_sentence_;
	std::vector<std::string> translated_word_sentence_;

	Composition_operations last_operation_;
};

}

#endif /* INCLUDE_CORE_SENTENCETRANSLATIONDATAMODEL_HPP_ */
