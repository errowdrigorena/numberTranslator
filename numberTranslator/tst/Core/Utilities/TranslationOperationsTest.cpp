/*
 * NonComposablesTest.cpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */

#include <Core/Utilities/TranslationOperations.hpp>
#include <gtest/gtest.h>
#include <tuple>

namespace core
{
namespace utilities
{

using Word_translation_result = std::tuple<std::string, char, bool>;

class Units_fixture_test : public testing::TestWithParam<Word_translation_result>
{
public:
};

TEST_P(Units_fixture_test, WordToUnitTest)
{
  auto word_translation_result = GetParam();
  auto word_to_test = std::get<0>(word_translation_result);
  auto expected_translation = std::get<1>(word_translation_result);
  auto is_correct_translation = std::get<2>(word_translation_result);

  auto result = translate_units(word_to_test);

  if(is_correct_translation)
  {
	  ASSERT_EQ(result, expected_translation);
  }
  else
  {
	  ASSERT_NE(result, expected_translation);
  }
}

INSTANTIATE_TEST_CASE_P(AllUnits, Units_fixture_test, testing::Values(
		std::make_tuple("a", 0, true),
		std::make_tuple("one", '1', true),
		std::make_tuple("two", '2', true),
		std::make_tuple("Three", '3',true),
		std::make_tuple("foUr", '4', true),
		std::make_tuple("five", '5', true),
		std::make_tuple("six", '6',true),
		std::make_tuple("seven", '7', true),
		std::make_tuple("eIght", '8', true),
		std::make_tuple("nine", '9', true),
		std::make_tuple("apple", '1', false)
));

class Decimals_fixture_test : public testing::TestWithParam<Word_translation_result>
{
public:
};

TEST_P(Decimals_fixture_test, WordToDecimalTest)
{
  auto word_translation_result = GetParam();
  auto word_to_test = std::get<0>(word_translation_result);
  auto expected_translation = std::get<1>(word_translation_result);
  auto is_correct_translation = std::get<2>(word_translation_result);

  auto result = translate_decimals(word_to_test);

  if(is_correct_translation)
  {
	  ASSERT_EQ(result, expected_translation);
  }
  else
  {
	  ASSERT_NE(result, expected_translation);
  }
}

INSTANTIATE_TEST_CASE_P(AllDecimals, Decimals_fixture_test, testing::Values(
		std::make_tuple("a", 0, true),
		std::make_tuple("twenty", '2', true),
		std::make_tuple("Thirty", '3',true),
		std::make_tuple("FortY", '4', true),
		std::make_tuple("FiFty", '5', true),
		std::make_tuple("SiXtY", '6',true),
		std::make_tuple("Seventy", '7', true),
		std::make_tuple("Eighty", '8', true),
		std::make_tuple("ninety", '9', true),
		std::make_tuple("apple", '1', false)
));

using Word_translationstring_result = std::tuple<std::string, std::string, bool>;

class Teens_fixture_test : public testing::TestWithParam<Word_translationstring_result>
{
public:
};

INSTANTIATE_TEST_CASE_P(AllTeens, Teens_fixture_test, testing::Values(
		std::make_tuple("a", "", true),
		std::make_tuple("Eleven", "11", true),
		std::make_tuple("twelve", "12", true),
		std::make_tuple("thirTeen", "13",true),
		std::make_tuple("foUrteeN", "14", true),
		std::make_tuple("Fifteen", "15", true),
		std::make_tuple("sixTEEN", "16", true),
		std::make_tuple("seventeen", "17", true),
		std::make_tuple("eIghteen", "18", true),
		std::make_tuple("nineTeen", "19", true),
		std::make_tuple("Ten", "10", true),
		std::make_tuple("apple", "1", false)
));

TEST_P(Teens_fixture_test, WordToTeenTest)
{
  auto word_translation_result = GetParam();
  auto word_to_test = std::get<0>(word_translation_result);
  auto expected_translation = std::get<1>(word_translation_result);
  auto is_correct_translation = std::get<2>(word_translation_result);

  auto result = translate_teens(word_to_test);

  if(is_correct_translation)
  {
	  ASSERT_EQ(result, expected_translation);
  }
  else
  {
	  ASSERT_NE(result, expected_translation);
  }
}

} //end utilities
} //end core

