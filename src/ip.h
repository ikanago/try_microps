#include <cstdint>
#include <optional>
#include <string>

namespace mps {

using ip_addr_t = std::uint32_t;

auto parse_ip_address(const std::string& s) -> std::optional<ip_addr_t>;

}  // namespace mps
