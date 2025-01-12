#ifndef _FLAGS_HPP
#define _FLAGS_HPP
#include <cstddef>

/// Example: 
///    FLAGS_ENUM(Test, F1, F2, F3)
///    DEFINE_FLAGS(TestFlag, Test)
///    TestFlag f;
///    

template<typename /* An enum genrates by FLAGS_ENUM */>
class flags;

#define FLAGS_ENUM(name, ...) enum name {__VA_ARGS__, ENUM_END};
#define DEFINE_FLAGS(name, flag_enum) using name = flags<flag_enum>;

template<typename _flags_enum>
class flags {
private:
    constexpr static auto get_index(_flags_enum flag) {
        return (flag / BYTE_SIZE) + (flag % BYTE_SIZE != 0 ? 1 : 0);
    }
public:
    constexpr static auto BYTE_SIZE = 8; /* size of byte(bits) */
    constexpr static auto bytes = get_index(_flags_enum::ENUM_END);

    flags() = default;
    ~flags() = default;

    template<_flags_enum flag>
    inline flags &set_flag(bool data) {
        constexpr auto x = flag / 32;
        constexpr auto y = flag % 32;

        if (data) {
            _flags[x] = 1 << y;
        } else {
            _flags[x] &= ~(1 << y);
        }

        return *this;
    }

    template <_flags_enum flag>
    inline bool get_flag() {
        constexpr auto x = flag / 32;
        constexpr auto y = flag % 32;

        return (_flags[x] & (1 << y));
    }

    inline flags &clear() {
        _flags = {0};

        return *this;
    }


private:
    std::byte _flags[bytes] = {(std::byte)0};
};

#endif // !_FLAGS_HPP
