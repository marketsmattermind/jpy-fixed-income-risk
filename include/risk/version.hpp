#ifndef JPY_FIXED_INCOME_RISK_VERSION_HPP
#define JPY_FIXED_INCOME_RISK_VERSION_HPP

#include <string_view>

namespace risk {

[[nodiscard]] constexpr std::string_view get_version() noexcept {
	return "0.1.0";
}

} // namespace risk

#endif // JPY_FIXED_INCOME_RISK_VERSION_HPP
