#ifndef ANALYTICS_LEVEL_1_BLACK_SCHOLES_BACHELIER_BLACK76_HPP
#define ANALYTICS_LEVEL_1_BLACK_SCHOLES_BACHELIER_BLACK76_HPP

namespace analytics::black76 {

	enum class OptionType {
		Call,
		Put
	};

	/**
	 * @brief Computes the European option price on a forward asset using Black-76 model.
	 *
	 * @param forward Forward price/rate (F0 > 0)
	 * @param strike Strike price/rate (K > 0)
	 * @param time_to_maturity Time to expiration in years (T > 0)
	 * @param discount_factor Discount factor P(0, T) to maturity
	 * @param volatility Annualized log-normal volatility (sigma > 0)
	 * @param type OptionType::Call or OptionType::Put
	 * @return Fair value of the option
	 */
	[[nodiscard]] double price(
			double forward,
			double strike,
			double time_to_maturity,
			double discount_factor,
			double volatility,
			OptionType type
	) noexcept;

} // namespace analytics::black76

#endif // ANALYTICS_LEVEL1_BLACK_SCHOLES_BACHELIER_BLACK76_HPP

