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

TEST(AuxiliarOperationTest, lowerConversion) {
	auto hello = convert_to_lowercase("HelLO");
	EXPECT_EQ("hello", hello);
}

}
