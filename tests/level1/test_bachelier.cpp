#include <gtest/gtest.h>
#include "analytics/level1/bachelier.hpp"

// Test standard positive forward rate scenario
TEST(BachelierTest, StandardPositiveForwardCall) {
	// F0 = 0.02 (2%), K = 0.02, T = 1.0, P(0,T) = 0.98, sigma_N = 0.01 (100 bps)
	const double call_price = analytics::bachelier::price(
			0.02, 0.02, 1.0, 0.98, 0.01, analytics::bachelier::OptionType::Call
	);

	// Theoretical Bachelier call price ~ 0.00390957
	EXPECT_NEAR(call_price, 0.00390957, 1e-6);
}

// Test Negative JPY Interest Rate scenario (NIRP)
TEST(BachelierTest, NegativeRateSupportNIRP) {
	// F0 = -0.0010 (-10 bps), K = -0.0005 (-5 bps), T = 0.5, P(0,T) = 1.0, sigma_N = 0.0050 (50 bps)
	const double call_price = analytics::bachelier::price(
			-0.0010, -0.0005, 0.5, 1.0, 0.0050, analytics::bachelier::OptionType::Call
	);

	// Theoretical call price remains strictly positive and mathematically defined
	EXPECT_GT(call_price, 0.0);

	// Put-Call Parity Verification: C - P = P(0,T) * (F0 - K)
	const double put_price = analytics::bachelier::price(
			-0.0010, -0.0005, 0.5, 1.0, 0.0050, analytics::bachelier::OptionType::Put
	);
	const double parity_diff = call_price - put_price;
	const double expected_diff = 1.0 * (-0.0010 - (-0.0005));

	EXPECT_NEAR(parity_diff, expected_diff,, 1e-9);
}

