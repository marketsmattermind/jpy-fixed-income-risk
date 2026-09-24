#include "analytics/level1/black_scholes.hpp"
#include <cmath>
#include <numbers>

namespace analytics::black_scholes {

namespace {
[[nodiscard]] double norm_cdf(double x) noexcept {
	return 0.5 * std::erfc(-x * std::numbers::sqrt2 / 2.0);
}
} // namespace

double price(
		double spot,
		double strike,
		double time_to_maturity,
		double risk_free_rate,
		double dividend_yield,
		double volatility,
		OptionType type
) noexcept {
	if (time_to_maturity <= 0.0 || volatility <= 0.0 || spot <= 0.0 || strike <= 0.0) {
		return 0.0;
	}

	const double std_dev = volatility * std::sqrt(time_to_maturity);
	const double d1 = (std::log(spot / strike) + (risk_free_rate - dividend_yield + 0.5 * volatility * volatility) * time_to_maturity) / std_dev;
	const double d2 = d1 - std_dev;

	const double df_r = std::exp(-risk_free_rate * time_to_maturity);
	const double df_q = std::exp(-dividend_yield * time_to_maturity);

	if (type == OptionType::Call) {
		return spot * df_q *norm_cdf(d1) - strike * df_r * norm_cdf(d2);
	} else {
		return strike * df_r * norm_cdf(-d2) - spot * df_q * norm_cdf(-d1);
	}
}

} // namespace analytics::black_scholes
