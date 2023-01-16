/*
 * AuxiliarOperationsTest.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#include <Core/Utilities/AuxiliarOperations.hpp>
#include <gtest/gtest.h>
#include <tuple>

namespace core
{

TEST(AuxiliarOperationTest, lowerConversion)
{
	auto hello = convert_to_lowercase("HelLO");
	EXPECT_EQ("hello", hello);
}

TEST(AuxiliarOperationTest, readFile)
{
	auto file_content = read_file("AuxiliarFiles/test_line_by_line.txt");

	std::string expected_content{"abc.dfg hij!k?.mnñ." };
	EXPECT_EQ(expected_content, file_content);
}

TEST(AuxiliarOperationTest, readFileException)
{
	EXPECT_ANY_THROW(read_file("unexistingFile.txt"));
}

TEST(AuxiliarOperationTest, sliceTextIntoSentences)
{
	std::string text{"Hello. Hello World. Are you hungry.."};
	auto text_in_sentences = get_sentences(text);

	std::vector<std::string> expected_content{{"Hello"}, {"Hello World"}, {"Are you hungry"},{} };
	EXPECT_EQ(expected_content, text_in_sentences);
}

TEST(AuxiliarOperationTest, sliceSentenceIntoWords)
{
	std::string text{"Hello World today is a beautiful day"};
	auto sentence_in_words = get_words(text);

	std::vector<std::string> expected_content{{"Hello"}, {"World"}, {"today"}, {"is"}, {"a"}, {"beautiful"}, {"day"} };
	EXPECT_EQ(expected_content, sentence_in_words);
}

TEST(AuxiliarOperationTest, writeFile)
{
	write_file("AuxiliarFiles/test_writting.txt", "Hello");
	auto file_content = read_file("AuxiliarFiles/test_writting.txt");

	std::string expected_content{"Hello" };
	EXPECT_EQ(expected_content, file_content);
}

}
