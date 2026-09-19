#include "analytics/level1_black_scholes_bachelier/bachelier.hpp"
#include <cmath>
#include <numbers>

namespace analytics::bachelier {

	namespace {
		// Standard normal cumulative distribution function N(x)
		[[nodiscard]] double norm_cdf(double x) noexcept {
			return 0.5 * std::erfc(-x * std::numbers::sqrt2 / 2.0);
		}

		[[nodiscard]] double norm_pdf(double x) noexcept {
			return (1.0 / std::sqrt(2.0 * std::numbers::pi)) * std::exp(-0.5 * x * x);
		}
	}  // namespace

double price(
	double forward,
	double strike,
	double time_to_maturity,
	double discount_factor,
	double normal_volatility,
	OptionType type
) noexcept {
	if (time_to_maturity <= 0.0 || normal_volatility <= 0.0) {
		return 0.0;
	}

	const double std_dev = normal_volatility * std::sqrt(time_to_maturity);
	const double d = (forward - strike) / std_dev; 
	const double call_price = discount_factor * ((forward - strike) * norm_cdf(d) + std_dev * norm_pdf(d));

	if (type == OptionType::Call) {
		return call_price;
	} else {
		// Put price via Put-Call Parity: Put = Call - P(0,T)*(F0 - K)
		return call_price - discount_factor * (forward - strike);
	}
}

} // namespacec analytics::bachelier

