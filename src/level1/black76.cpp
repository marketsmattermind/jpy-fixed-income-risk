#include "analytics/level1_black_scholes_bachelier/black76.hpp"
#include <cmath>
#include <numbers>

namespace analytics::black76 {

	namespace {
		// Cumulative distribution function of standard normal distribution: N(x)
		[[nodiscard]] double norm_cdf(double x) noexcept {
			return 0.5 * std::erfc(-x * std::numbers::sqrt2 / 2.0);
		}
	}  // namespace

double price(
	double forward,
	double strike,
	double time_to_maturity,
	double discount_factor,
	double volatility,
	OptionType type
) noexcept {
	if (time_to_maturity <= 0.0 || volatility <= 0.0 || forward <= 0.0 || strike <= 0.0) {
		return 0.0;
	}

	const double std_dev = volatility * std::sqrt(time_to_maturity);
	const double d1 = (std::log(forward / strike) + 0.5 * std_dev * std_dev) / std_dev;
	const double d2 = d1 - std_dev;

	if (type == OptionType::Call) {
		return discount_factor * (forward * norm_cdf(d1) - strike * norm_cdf(d2));
	} else {
		return discount_factor * (strike * norm_cdf(-d2) - forward * norm_cdf(-d1));
	}
}

} // namespacec analytics::black76

