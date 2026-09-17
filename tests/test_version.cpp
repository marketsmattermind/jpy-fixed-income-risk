#include <gtest/gtest.h>
#include "jpy_risk/version.hpp"

TEST(VersionTest, SanityCheck) {
	// Basic assertion to ensure GoogleTest runner functions correctly
	EXPECT_EQ(jpy_risk::get_version(), "0.1.0");
}

