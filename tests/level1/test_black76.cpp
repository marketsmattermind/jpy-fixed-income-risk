#include <gtest/gtest.h>
#include "analytics/level1/black76.hpp"

TEST(Black76Test, EuropeanCallKnownValue) {
	// F0 = 100, K = 100, T = 1.0, P(0,T) = 0.95, sigma = 0.20
	double call_price = analytics::black76::price(100.0, 100.0, 1.0, 0.95, 0.20, analytics::black76::OptionType::Call);

	// Exact mathematical value is ~ 7.56728908
	EXPECT_NEAR(call_price, 7.567289, 1e-5);
}

