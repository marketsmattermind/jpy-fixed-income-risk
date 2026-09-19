#include <gtest/gtest.h>
#include "analytics/level1/black76.hpp"

TEST(Black76Test, EuropeanCallKnownValue) {
	// F0 = 100, K = 100, T = 1.0, P(0,T) = 0.95, sigma = 0.20
	double call_price = analytics::black76::price(100.0, 100.0, 1.0, 0.95, 0.20, analytics::black76::OptionType::Call);

	// Theoretical value is ~7.5627
	EXPECT_NEAR(call_price, 7.5627, 1e-4);
}

