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

TEST_F(NumberCompositionHandlerTestFixture, unitHundredNumber)
{
  std::vector<std::string> sentence{{"I"}, {"have"}, {"one"}, {"hundred"}, {"apples"}};

  ASSERT_EQ("I have 100 apples.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredAndUnitNumber)
{
  std::vector<std::string> sentence{{"One"}, {"hundred"}, {"and"}, {"one"}};

  ASSERT_EQ("101.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredUnitNumber)
{
  std::vector<std::string> sentence{{"One"}, {"hundred"}, {"one"}, {"guys"}};

  ASSERT_EQ("100 1 guys.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredDecimalNumber)
{
  std::vector<std::string> sentence{{"Two"}, {"hundred"}, {"forty"}};

  ASSERT_EQ("200 40.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredAndDecimalNumber)
{
  std::vector<std::string> sentence{{"Two"}, {"hundred"}, {"and"}, {"forty"}};

  ASSERT_EQ("240.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitGuidonDecimalNumbers)
{
  std::vector<std::string> sentence{{"Two"}, {"sixty-six"}};

  ASSERT_EQ("2 66.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalUnitNumbers)
{
  std::vector<std::string> sentence{{"sixty-six"}, {"Two"}};

  ASSERT_EQ("66 2.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredAndGuidonDecimalNumber)
{
  std::vector<std::string> sentence{{"Two"}, {"hundred"}, {"and"}, {"forty-eight"}};

  ASSERT_EQ("248.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredGuidonDecimalNumber)
{
  std::vector<std::string> sentence{{"Two"}, {"hundred"}, {"forty-eight"}};

  ASSERT_EQ("200 48.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalHundredNumbers)
{
  std::vector<std::string> sentence{{"seventy-seven"}, {"hundred"}};

  ASSERT_EQ("77 hundred.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, teenHundredNumbers)
{
  std::vector<std::string> sentence{{"seventeen"}, {"hundred"}};

  ASSERT_EQ("17 hundred.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredAndTeenNumber)
{
  std::vector<std::string> sentence{{"Five"}, {"hundred"}, {"and"}, {"ten"}};

  ASSERT_EQ("510.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredTeenNumber)
{
  std::vector<std::string> sentence{{"Five"}, {"hundred"}, {"ten"}};

  ASSERT_EQ("500 10.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandNumber)
{
  std::vector<std::string> sentence{{"One"}, {"thowsand"}, {"times"}};

  ASSERT_EQ("1000 times.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, aThowsandNumber)
{
  std::vector<std::string> sentence{{"A"}, {"thowsand"}, {"times"}};

  ASSERT_EQ("A thowsand times.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandUnitNumber)
{
  std::vector<std::string> sentence{{"Three"}, {"thowsand"}, {"three"}};

  ASSERT_EQ("3000 3.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandAndUnitNumber)
{
  std::vector<std::string> sentence{{"Three"}, {"thowsand"}, {"and"}, {"three"}};

  ASSERT_EQ("3003.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitUnitUnitNumbers)
{
  std::vector<std::string> sentence{{"Three"}, {"two"}, {"one"}};

  ASSERT_EQ("3 2 1.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, decimalDecimalGuidonDecimalTeenNumbers)
{
  std::vector<std::string> sentence{{"thirty"}, {"ninety"}, {"ninety-nine"}, {"nineteen"}};

  ASSERT_EQ("30 90 99 19.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandTeenNumber)
{
  std::vector<std::string> sentence{{"Three"}, {"thowsand"}, {"ten"}};

  ASSERT_EQ("3000 10.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandAndTeenNumber)
{
  std::vector<std::string> sentence{{"Three"}, {"thowsand"}, {"and"}, {"ten"}};

  ASSERT_EQ("3010.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandAndUnitHundredNumber)
{
  std::vector<std::string> sentence{{"Three"}, {"thowsand"}, {"and"}, {"nine"}, {"hundred"}};

  ASSERT_EQ("3900.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandAndUnitHundredAndTeenNumber)
{
  std::vector<std::string> sentence{{"Three"}, {"thowsand"}, {"and"}, {"nine"}, {"hundred"}, {"and"}, {"eleven"}};

  ASSERT_EQ("3911.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, teenThowsandAndUnitHundredAndDecimalNumber)
{
  std::vector<std::string> sentence{{"Ten"}, {"thowsand"}, {"and"}, {"three"}, {"hundred"}, {"and"}, {"eighty"}};

  ASSERT_EQ("10380.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, decimalThowsandAndUnitHundredAndGuidonDecimalNumber)
{
  std::vector<std::string> sentence{{"Fifty"}, {"thowsand"}, {"and"}, {"three"}, {"hundred"}, {"and"}, {"fifty-five"}};

  ASSERT_EQ("50355.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, guidonDecimalThowsandAndUnitHundredAndGuidonDecimalNumber)
{
  std::vector<std::string> sentence{{"Fifty-four"}, {"thowsand"}, {"and"}, {"six"}, {"hundred"}, {"and"}, {"ninety-five"}};

  ASSERT_EQ("54695.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitAndUnitNumbers)
{
	  std::vector<std::string> sentence{{"One"}, {"and"}, {"two"}};

	  ASSERT_EQ("1 and 2.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitThowsandAndWord)
{
	  std::vector<std::string> sentence{{"One"}, {"thowsand"}, {"and"}, {"thanks"}};

	  ASSERT_EQ("1000 and thanks.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredAndGuidonDecimalThowsandAndUnitHundredAndGuidonDecimalNumber)
{
  std::vector<std::string> sentence{{"One"},{"hundred"},{"and"},{"Fifty-four"}, {"thowsand"}, {"and"}, {"six"},
	  {"hundred"}, {"and"}, {"ninety-five"}};

  ASSERT_EQ("154695.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredThowsandNumber)
{
  std::vector<std::string> sentence{{"One"}, {"hundred"},{"thowsand"}};

  ASSERT_EQ("100000.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndUnit)
{
	  std::vector<std::string> sentence{{"Two"}, {"million"}, {"and"}, {"three"}};

	  ASSERT_EQ("2000003.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndDecimalNumber)
{
	  std::vector<std::string> sentence{{"Two"}, {"million"}, {"and"}, {"forty"}, {"pies"}};

	  ASSERT_EQ("2000040 pies.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"Two"}, {"million"}, {"and"}, {"five"}, {"hundred"}};

	  ASSERT_EQ("2000500.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndUnitThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"Two"}, {"million"},
		  {"and"}, {"two"}, {"thowsand"},{"and"}, {"five"}, {"hundred"}};

	  ASSERT_EQ("2002500.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndGuidoDecimalThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"five"}, {"million"},
		  {"and"}, {"sixty-two"}, {"thowsand"},{"and"}, {"nine"}, {"hundred"}};

	  ASSERT_EQ("5062900.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndUnitHunredThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"five"}, {"million"},
		  {"and"}, {"five"}, {"hundred"}, {"thowsand"},{"and"}, {"nine"}, {"hundred"}};

	  ASSERT_EQ("5500900.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitMilliondAndUnitHunredAndGuidonDecimalThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"five"}, {"million"},
		  {"and"}, {"five"}, {"hundred"}, {"and"}, {"sixty-nine"}, {"thowsand"},{"and"}, {"nine"}, {"hundred"}};

	  ASSERT_EQ("5569900.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, teenMilliondAndUnitHunredAndGuidonDecimalThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"fourteen"}, {"million"},
		  {"and"}, {"five"}, {"hundred"}, {"and"}, {"sixty-nine"}, {"thowsand"},{"and"}, {"nine"}, {"hundred"}};

	  ASSERT_EQ("14569900.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredMilliondAndUnitHundredAndGuidonDecimalThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"nine"}, {"hundred"}, {"million"},
		  {"and"}, {"five"}, {"hundred"}, {"and"}, {"sixty-nine"}, {"thowsand"},{"and"}, {"nine"}, {"hundred"}};

	  ASSERT_EQ("900569900.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, unitHundredAndGuidonDecimalMilliondAndUnitHundredAndGuidonDecimalThowsandAndUnitHundredNumber)
{
	  std::vector<std::string> sentence{{"nine"}, {"hundred"}, {"and"}, {"ninety-nine"},{"million"},
		  {"and"}, {"nine"}, {"hundred"}, {"and"}, {"ninety-nine"}, {"thowsand"},{"and"}, {"nine"}, {"hundred"},
	  {"and"}, {"ninety-nine"}};

	  ASSERT_EQ("999999999.", translateSentence(sentence));
}

TEST_F(NumberCompositionHandlerTestFixture, oneBillion)
{
  std::vector<std::string> sentence{{"One"}, {"Billion"}, {"coins"}};

  ASSERT_EQ("1000000000 coins.", translateSentence(sentence));
}

}
