cmake_minimum_required(VERSION 3.20)

project(
	jpy_fixed_income_risk
	VERSION 0.1.0
	DESCRIPTION "JPY Fixed Income & Rates Analytics Engine"
	LANGUAGES CXX
)

# -------------------------------------------------------------
# 1. C++ Standard Enforcement (C++20 Strict)
# -------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions (e.g. gnu++20)

# Export compile commands for IDE support (clangd, VS Code, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------------------------------------------------------------
# 2. Strict Compiler Warning Options
# -------------------------------------------------------------
add_library(project_warnings INTERFACE)

if(MSVC)
	target_compile_options(project_warnings INTERFACE /W4 /WX /permissive-)
else()
	target_compile_options(project_warnings INTERFACE
		-Wall
		-Wextra
		-Wpedantic
		-Werror			# Treat warnings as errors
		-Wshadow		# Warn if a variable declaration shadows another
		-Wnon-virtual-dtor	# Warn if a class with virtual functions has non-virtual destructor
		-Wold-style-cast	# Warn on C-style casts
		-Wcast-align		# Warn for potential performance/alignment issues
		-Wunused		# Warn on anything unused
		-Wconversion		# Warn on type conversions that may lose data
		-Wsign-conversion	# Warn on sign conversions
	)
endif()

# -------------------------------------------------------------
# 3. Core Engine Library Target (Modular Source Architecture)
# -------------------------------------------------------------
# As we implement each pricing level, we list its active C++ files below:
set(ENGINE_SOURCES
	# Level 1: Black-Scholes & Bachelier; Analytic Benchmarks
	# src/level1_black_scholes_bachelier/bachelier.cpp
	src/level1_black_scholes_bachelier/black76.cpp
	# src/level1_black_scholes_bachelier/black_scholes.cpp

	# Level 2: Stochastic Volatility
	# src/level2_heston/heston_cos.cpp

	# Level 3: Non-parametric Volatility
	# src/level3_sabr/sabr.cpp

	# Level 4: Short-rate Term Structure
	# src/level4_hull_white/hull_white.cpp

	# Level 5: Whole-yield-curve Forward Rate Dynamics
	# src/level5_heath_jarrow_morton/heath_jarrow_morton.cpp

	# Risk Engine & Sensitivities
	# src/risk/greeks.cpp
)

add_library(jpy_fixed_income_risk STATIC
	${ENGINE_SOURCES}
)

# Placeholder target keeps build valid until the first .cpp file is populated; make the library build valid even before the first .cpp file is added
if(NOT ENGINE_SOURCES)
	target_sources(jpy_fixed_income_risk PRIVATE cmake/empty_target.cpp)
endif()

# Expose the entire include/ root (analytics/, risk/, jpy_risk/)
target_include_directories(jpy_fixed_income_risk
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(jpy_fixed_income_risk
	PRIVATE
		project_warnings
)

# -------------------------------------------------------------
# 4. GoogleTest Integration via FetchContent
# -------------------------------------------------------------
option(BUILD_TESTS "Build the unit test suite" ON)

if(BUILD_TESTS)
	include(FetchContent)

	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
	)

	# For Windows MSVC runtime compatibility
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	FetchContent_MakeAvailable(googletest)

	enable_testing()
	add_subdirectory(tests)
endif()
