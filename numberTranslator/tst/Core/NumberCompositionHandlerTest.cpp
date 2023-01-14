/*
 * NumberCompositionHandler.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */
#include <Core/NumberCompositionHandler.hpp>
#include <gtest/gtest.h>

#include <vector>

namespace core
{

class NumberCompositionHandlerTestFixture : public testing::Test
{
};

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalNumber)
{
  std::vector<std::string> sentence{{"Cow-boy"}, {"loves"}, {"fifty-five"}, {"flowers"}};

  Number_composition_handler handler{sentence};
  auto translated_sentence = handler.get_sentence_with_numbers();
  std::cout << translated_sentence << std::endl;
  ASSERT_EQ("Cow-boy loves 55 flowers.", translated_sentence);
}

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalNumberAtEndLine)
{
  std::vector<std::string> sentence{{"I"}, {"am"}, {"thirty-two"}};

  Number_composition_handler handler{sentence};
  auto translated_sentence = handler.get_sentence_with_numbers();
  std::cout << translated_sentence << std::endl;
  ASSERT_EQ("I am 32.", translated_sentence);
}

TEST_F(NumberCompositionHandlerTestFixture, decimalNumber)
{
  std::vector<std::string> sentence{{"I"}, {"am"}, {"thirty"}, {"yes"}};

  Number_composition_handler handler{sentence};
  auto translated_sentence = handler.get_sentence_with_numbers();
  std::cout << translated_sentence << std::endl;
  ASSERT_EQ("I am 30 yes.", translated_sentence);
}

}
