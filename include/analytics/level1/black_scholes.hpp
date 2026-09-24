#ifndef ANALYTICS_LEVEL1_BLACK_SCHOLES_HPP
#define ANALYTICS_LEVEL1_BLACK_SCHOLES_HPP

namespace analytics::black_scholes {

	enum class OptionType {
		Call,
		Put
	};

/**
 * @brief Computes European option price on a spot asset using Black-Scholes model.
 *
 * @param spot Spot price/rate (S0 > 0)
 * @param strike Strike price/rate (K > 0)
 * @param time_to_maturity Time to expiration in years (T > 0)
 * @param risk_free_rate Continuous risk-free interest rate (r)
 * @param dividend_yield Continuous dividend/foreign rate yield (q)
 * @param volatility Annualized log-normal volatility (sigma > 0)
 * @param type OptionType::Call or OptionType::Put
 * @return Fair value of the option
 */

[[nodiscard]] double price(
		double spot,
		double strike,
		double time_to_maturity,
		double risk_free_rate,
		double dividend_yield,
		double volatility,
		OptionType type
) noexcept;

} // namespace analytics::black_scholes

#endif // ANALYTICS_LEVEL1_BLACK_SCHOLES_HPP

