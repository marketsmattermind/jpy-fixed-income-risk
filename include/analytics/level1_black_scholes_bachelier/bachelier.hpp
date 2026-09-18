#ifndef ANALYTICS_LEVEL1_BLACK_SCHOLES_BACHELIER_BACHELIER_HPP
#define ANALYTICS_LEVEL1_BLACK_SCHOLES_BACHELIER_BACHELIER_HPP

namespace analytics::bachelier{

	enum class OptionType {
		Call,
		Put
	};

	/**
	 * @brief Computes the European option price using Bachelier (normal volatility) model.
	 * Supports negative forward rates (F0 < 0) and strikes (K < 0).
	 *
	 * @param forward Forward price/rate (F0) - can be negative
	 * @param strike Strike price/rate (K) - can be negative
	 * @param time_to_maturity Time to expiration in years (T > 0)
	 * @param discount_factor Discount factor P(0, T)
	 * @param normal_volatility Annualized normal volatility in absolute units/bps (sigma_N > 0)
	 * @param type OptionType::Call or OptionType::Put
	 * @return Fair value of the option
	 */
	[[nodiscard]] double price(
			double forward,
			double strike,
			double time_to_maturity,
			double discount_factor,
			double normal_volatility,
			OptionType type
	) noexcept;

} // namespace analytics::bachelier

#endif // ANALYTICS_LEVEL1_BLACK_SCHOLES_BACHELIER_BACHELIER_HPP

