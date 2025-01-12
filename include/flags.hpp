#ifndef _FLAGS_HPP
#define _FLAGS_HPP
#include <cstddef>
#include <type_traits>

/// Example: 
///
///    DEFINE_FLAGS(TestFlag, F1, F2, F3)
///    TestFlag f;
///    

template<typename /* An enum genrates by FLAGS_ENUM */>
class flags;

#define FLAGS_ENUM(name, ...) enum name {__VA_ARGS__, ENUM_END};
#define DEFINE_FLAGS(name, ...) FLAGS_ENUM(__##name_ENUM__, __VA_ARGS__) using name = flags<__##name_ENUM__>;

template<typename _flags_enum>
class flags {
    static_assert(std::is_enum_v<_flags_enum>, "flags<_flags_enum> needs an enum structure for _flags_enum. Please use DEFINE_FLAGS or FLAGS_ENUM macro");
public:
    constexpr static auto BYTE_SIZE = 8; /* size of byte(bits) */
    constexpr static auto bytes = (_flags_enum::ENUM_END / BYTE_SIZE) + (_flags_enum::ENUM_END % BYTE_SIZE != 0 ? 1 : 0);

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
