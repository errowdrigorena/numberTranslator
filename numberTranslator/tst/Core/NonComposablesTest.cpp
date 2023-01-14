/*
 * NonComposablesTest.cpp
 *
 *  Created on: Jan 13, 2023
 *      Author: iban
 */

#include <Core/NonComposables.hpp>
#include <gtest/gtest.h>

namespace core
{

TEST(NonComposableTest, BasicAssertions) {
	EXPECT_EQ(1, dummyOne());
}

}


