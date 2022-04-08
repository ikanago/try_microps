#include "socket.h"

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>

#include "udp.h"

auto mps::SocketManager::allocate_socket() -> std::tuple<size_t, std::shared_ptr<Socket>> {
    for (size_t i = 0; i < this->sockets_.size(); i++) {
        auto entry = this->sockets_.at(i);
        if (!entry->is_used) {
            entry->is_used = true;
            return {i, entry};
        }
    }

    return {0, nullptr};
}

mps::SocketManager::SocketManager()
    : sockets_(mps::SocketManager::N_SOCKETS, std::make_shared<Socket>()) {}

auto mps::SocketManager::open_socket(const std::int32_t domain, const std::int32_t type,
                                     const std::int32_t protocol) -> std::optional<size_t> {
    if (domain != mps::AF_INET) {
        return std::nullopt;
    }

    if (type != mps::SOCK_STREAM && type != mps::SOCK_DGRAM) {
        return std::nullopt;
    }

    if (protocol != 0) {
        return std::nullopt;
    }

    auto [index, socket] = this->allocate_socket();
    if (!socket) {
        return std::nullopt;
    }

    socket->family = domain;
    socket->type = type;

    switch (socket->type) {
        case SOCK_STREAM:
            return std::nullopt;
        case SOCK_DGRAM:
            socket->descriptor = open_udp();
            break;
    }

    if (socket->descriptor == -1) {
        return std::nullopt;
    }
    return index;
}
