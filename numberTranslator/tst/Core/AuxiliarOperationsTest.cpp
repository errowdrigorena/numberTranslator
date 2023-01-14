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
	auto file_line_by_line = read_file_line_by_line("abc.txt");
	//EXPECT_EQ("hello", hello);
	EXPECT_EQ(true, false);
}

}
