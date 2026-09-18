# -------------------------------------------------------------
# JPY Fixed Income Risk Engine - Unit Test Harness
# -------------------------------------------------------------

# Create the test runner executable target
add_executable(jpy_risk_tests
	test_version.cpp
	level1_black_scholes_bachelier/test_black76.cpp
)

# Link against our core engine library, warning flags, and GoogleTest main entry point
target_link_libraries(jpy_risk_tests
	PRIVATE
		jpy_fixed_income_risk
		project_warnings
		gtest_main
)

# Enable automatic test discovery for CTest / IDEs
include(GoogleTest)
gtest_discover_tests(jpy_risk_tests)
