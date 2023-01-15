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
public:
	std::string translateSentence(std::vector<std::string> sentenceInWords)
	{
		  Number_composition_handler handler{sentenceInWords};
		  auto translated_sentence = handler.get_sentence_with_numbers();
		  std::cout << translated_sentence << std::endl;

		  return translated_sentence;

	}

};

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalNumber)
{
  std::vector<std::string> sentence{{"Cow-boy"}, {"loves"}, {"fifty-five"}, {"flowers"}};

  ASSERT_EQ("Cow-boy loves 55 flowers.", translateSentence(sentence) );
}

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalNumberAtEndLine)
{
  std::vector<std::string> sentence{{"I"}, {"am"}, {"thirty-two"}};

  ASSERT_EQ("I am 32.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, decimalNumber)
{
  std::vector<std::string> sentence{{"I"}, {"am"}, {"thirty"}, {"yes"}};

  ASSERT_EQ("I am 30 yes.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitNumber)
{
  std::vector<std::string> sentence{{"John"}, {"is"}, {"two"}};

  ASSERT_EQ("John is 2.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitAfterDecimalNumber)
{
  std::vector<std::string> sentence{{"Ian"}, {"is"}, {"fifty"}, {"two"}, {"men"}, {"run"}};

  ASSERT_EQ("Ian is 50 2 men run.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, decimalAfterUnitNumber)
{
  std::vector<std::string> sentence{{"two"}, {"forty"}, {"women"}, {"shopping"}};

  ASSERT_EQ("2 40 women shopping.", translateSentence(sentence));
}

}
