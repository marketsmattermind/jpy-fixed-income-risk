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

// TBC

