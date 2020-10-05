#include <../gtest/gtest.h> 
#include "MyVector.h"

TEST(Vector, Name) {
	ASSERT_NO_THROW(Vector <int> v1);
}

TEST(Vector, Name2) {
	Vector<double>v1(5.1);


	EXPECT_EQ(1, v1.Length());
	for (int i = 0; i < v1.Length(); ++i) 
	EXPECT_EQ(5.1, v1[0]);
}