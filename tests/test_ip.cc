#include <gtest/gtest.h>
#include <optional>

#include "ip.h"

TEST(IpAddressTest, ParseValidIpAddress) {
    const auto address = std::string("192.16.0.1");
    ASSERT_EQ(0xc0100001, parse_ip_address(address));
}

TEST(IpAddressTest, ParseEmptyIpAddress) {
    const auto address = std::string("");
    ASSERT_EQ(std::nullopt, parse_ip_address(address));
}

TEST(IpAddressTest, ParseIpAddressWithBiggerDigit) {
    const auto address = std::string("256.16.0.1");
    ASSERT_EQ(std::nullopt, parse_ip_address(address));
}

TEST(IpAddressTest, ParseIpAddressWithOnly3Parts) {
    const auto address = std::string("192.16.0");
    ASSERT_EQ(std::nullopt, parse_ip_address(address));
}
