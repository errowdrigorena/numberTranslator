/*
 * AuxiliarOperationsTest.cpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#include <Core/AuxiliarOperations.hpp>
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
	std::string  file_content = read_file("AuxiliarFiles/test_line_by_line.txt");
	std::string expected_content{"abc.dfg hij!k?.mnñ." };
	EXPECT_EQ(expected_content, file_content);
}

}
