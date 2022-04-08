#include <cstdint>
#include <memory>
#include <optional>
#include <vector>

namespace mps {

constexpr std::int32_t AF_INET = 2;

constexpr std::int32_t SOCK_STREAM = 1;
constexpr std::int32_t SOCK_DGRAM = 2;

struct Socket {
    bool is_used;
    std::int32_t family;
    std::int32_t type;
    std::int32_t descriptor;
};

class SocketManager {
    std::vector<std::shared_ptr<Socket>> sockets_;

    constexpr static size_t N_SOCKETS = 128;

    auto allocate_socket() -> std::tuple<size_t, std::shared_ptr<Socket>>;

public:
    SocketManager();

    auto open_socket(const std::int32_t domain, const std::int32_t type,
                     const std::int32_t protocol) -> std::optional<size_t>;
};

}  // namespace mps
