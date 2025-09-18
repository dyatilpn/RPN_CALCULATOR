#include <gtest/gtest.h>
#include "rpn.h"
#include <stdexcept>

TEST(RPNTest, BasicOperations) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("2 3 +"), 5.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("10 5 -"), 5.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("4 3 *"), 12.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("20 4 /"), 5.0);
    EXPECT_DOUBLE_EQ(evaluate_rpn("9 2 ^"), 81.0);
}

TEST(RPNTest, ComplexExpression) {
    EXPECT_NEAR(evaluate_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -"), 5.0, 1e-9);
}

TEST(RPNTest, DivisionByZero) {
    EXPECT_THROW(evaluate_rpn("1 0 /"), std::invalid_argument);
}

TEST(RPNTest, InvalidExpression) {
    EXPECT_THROW(evaluate_rpn("2 +"), std::invalid_argument);
    EXPECT_THROW(evaluate_rpn("1 0 /"), std::invalid_argument);
    EXPECT_THROW(evaluate_rpn("a b +"), std::invalid_argument);
}

TEST(RPNTest, SinFunction) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("30 sin"), 0.5);
}

TEST(RPNTest, SinInvalidInput) {
    EXPECT_THROW(evaluate_rpn("sin"), std::invalid_argument);
}

TEST(RPNTest, CosFunction) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("60 cos"), 0.5);
}

TEST(RPNTest, CosInvalidInput) {
    EXPECT_THROW(evaluate_rpn("cos"), std::invalid_argument);
}
