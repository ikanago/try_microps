#include <gtest/gtest.h>
#include <optional>

#include "socket.h"

TEST(SocketTest, OpenSocket) {
    auto manager = mps::SocketManager();

    const auto socket = manager.open_socket(mps::AF_INET, mps::SOCK_DGRAM, 0);
    ASSERT_NE(std::nullopt, socket);
    ASSERT_EQ(0,  socket);
}
