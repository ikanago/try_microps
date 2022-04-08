#include <cstdint>
#include <string>
#include <optional>

using ip_addr_t = std::uint32_t;

auto parse_ip_address(const std::string& s) -> std::optional<ip_addr_t>;
