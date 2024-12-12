#include <gtest/gtest.h>

// Declaration of the isValidPercentage function (as provided in the question)
bool isValidPercentage(float first, float second, float third, float fourth, float fifth) {
  float total;
   total= first + second + third + fourth + fifth;
    return (total == 100); 
}

// Test valid percentages
TEST(ValidPercentageTest, CorrectSum) {
    EXPECT_TRUE(isValidPercentage(20.0f, 20.0f, 20.0f, 20.0f, 20.0f)); // Sum = 100, should return true
    EXPECT_TRUE(isValidPercentage(40.0f, 20.0f, 10.0f, 10.0f, 20.0f)); // Sum = 100, should return true
}

// Test invalid percentages
TEST(InvalidPercentageTest, IncorrectSum) {
    EXPECT_FALSE(isValidPercentage(25.0f, 25.0f, 25.0f, 25.0f, 30.0f)); // Sum = 130, should return false
    EXPECT_FALSE(isValidPercentage(10.0f, 10.0f, 10.0f, 10.0f, 20.0f)); // Sum = 60, should return false
    EXPECT_FALSE(isValidPercentage(50.0f, 30.0f, 10.0f, 10.0f, 5.0f)); // Sum = 105, should return false
}

