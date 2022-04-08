#include "ip.h"

#include <cstddef>
#include <optional>

auto parse_ip_address(const std::string& address) -> std::optional<ip_addr_t> {
    ip_addr_t result = 0;
    size_t has_read = 0;

    for (size_t i = 0; i < 4; i++) {
        if (address.length() - has_read <= 0) {
            return std::nullopt;
        }

        size_t digits = 0;
        const auto part = std::stoi(address.substr(has_read), &digits, 10);
        has_read += digits;

        if (part < 0 || part > 255) {
            return std::nullopt;
        }

        if ((i == 3 && has_read != address.length()) || (i != 3 && address[has_read] != '.')) {
            return std::nullopt;
        }

        // Proceed 1 character, '.'
        has_read += 1;
        result += part << ((3 - i) * 8);
    }

    return result;
}
