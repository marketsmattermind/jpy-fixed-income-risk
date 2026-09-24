#include <gtest/gtest.h>
#include "analytics/level1/black_scholes.hpp"

TEST(BlackScholesTest, EuropeanCallKnownValue) {
	// S0 = 100, K = 100, T = 1.0, r = 0.05, q = 0.02, sigma = 0.20
	const double call_price = analytics::black_scholes::price(
			100.0, 100.0, 1.0, 0.05, 0.02, 0.20, analytics::black_scholes::OptionType::Call
	);

	// Exact theoretical value is ~ 9.92506
	EXPECT_NEAR(call_price, 9.92506, 1e-5);
}

