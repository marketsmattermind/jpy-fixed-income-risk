#ifndef JPY_RISK_VERSION_HPP
#define JPY_RISK_VERSION_HPP

#include <string_view>

namespace jpy_risk {

[[nodiscard]] constexpr std::string_view get_version() noexcept {
	return "0.1.0";
}

} // namespace jpy_risk

#endif // JPY_RISK_VERSION_HPP
