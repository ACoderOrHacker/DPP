#ifndef _FLAGS_HPP
#define _FLAGS_HPP
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <limits>
#include <cereal/cereal.hpp>

/// Example:
///
///    DEFINE_FLAGS(TestFlag, F1, F2, F3)
///    TestFlag f;
///

template<typename /* An enum genrates by FLAGS_ENUM */>
class flags;

#define FLAGS_ENUM(name, ...) enum class name {__VA_ARGS__, ENUM_END};
#define DEFINE_FLAGS(name, ...) FLAGS_ENUM(__##name, __VA_ARGS__) using name = flags<__##name>;

template<typename _flags_enum>
class flags {
    static_assert(std::is_enum_v<_flags_enum>, "flags<_flags_enum> needs an enum structure for _flags_enum. Please use DEFINE_FLAGS or FLAGS_ENUM macro");
public:
    using byte = char;
    constexpr static auto BYTE_SIZE = std::numeric_limits<byte>::digits; /* size of byte(bits) */
    constexpr static auto bytes = ((uint64_t)_flags_enum::ENUM_END / BYTE_SIZE) + ((uint64_t)_flags_enum::ENUM_END % BYTE_SIZE != 0 ? 1 : 0);
    constexpr static auto flags_count = (uint64_t)_flags_enum::ENUM_END;

    flags() = default;
    ~flags() = default;

    flags(const flags &other) = default;
    flags(flags &&other) = default;


    flags &operator=(const flags &other) = default;
    flags &operator=(flags &&other) = default;

    /**
     * @brief set flag to true or false
     *
     * @tparam flag the flag to set
     * @param data true or false
     * @return flags& this object
     */
    template<_flags_enum flag>
    inline flags &set_flag(bool data) {
        constexpr auto x = (uint64_t)flag / 32;
        constexpr auto y = (uint64_t)flag % 32;

        if (data) {
            _flags[x] = 1 << y;
        } else {
            _flags[x] &= ~(1 << y);
        }

        return *this;
    }

    /**
     * @brief get flag value
     *
     * @tparam flag the flag to get
     * @return true the flag is true, false the flag is false
     */
    template <_flags_enum flag>
    inline bool get_flag() {
        constexpr auto x = (uint64_t)flag / 32;
        constexpr auto y = (uint64_t)flag % 32;

        return (_flags[x] & (1 << y));
    }

    /**
     * @brief get flag value
     *
     * @param flag the flag to get
     * @return true the flag is true, false the flag is false
     */
    inline bool get_flag(_flags_enum flag) const {
        auto x = (uint64_t)flag / 32;
        auto y = (uint64_t)flag % 32;

        return (_flags[x] & (1 << y));
    }

    inline flags &clear() {
        std::memset(_flags, 0, bytes);

        return *this;
    }

    /**
     * @brief check if all flags are false
     *
     * @return true the flags are all false
     * @return false the flags are not all false
     */
    [[nodiscard]] inline bool empty() const {
        for (auto &i : _flags) {
            if (i != byte(0)) {
                return false;
            }
        }

        return true;
    }


/* operators */
public:
    inline flags &operator ~() {
        return clear();
    }
private:
    byte _flags[bytes] {};

    friend class cereal::access;
    template<class Archive>
    void serialize(Archive &archive) {
        archive(cereal::make_nvp("flags", _flags));
    }
};

#endif // !_FLAGS_HPP
