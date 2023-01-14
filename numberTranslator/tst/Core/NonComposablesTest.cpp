/*
 * NonComposablesTest.cpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */

#include <Core/NonComposables.hpp>
#include <gtest/gtest.h>
#include <tuple>

namespace core
{

TEST(NonComposableTest, BasicAssertions) {
	EXPECT_EQ(1, dummyOne());
}

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

}


