

#ifndef _DPP_VERSIONDEF_HPP
#define _DPP_VERSIONDEF_HPP
#include "acdpp.h"
#include "macros.hpp"

NAMESPACE_DPP_BEGIN

class version {
public:
    struct version_base {
        uint8_t major;
        uint8_t minor;
        uint16_t patch;
    };

private:
    version_base version_;

public:
    version() = default;

    version(uint8_t major, uint8_t minor, uint16_t patch)
        : version_{major, minor, patch} {}

    ~version() = default;

    uint8_t major() const {
        return version_.major;
    }

    uint8_t minor() const {
        return version_.minor;
    }

    uint16_t patch() const {
        return version_.patch;
    }

    std::string to_string() const {
        return std::to_string(major()) + "." +
               std::to_string(minor()) + "." +
               std::to_string(patch());
    }

    bool operator ==(const version &other) const {
        return (this->major() == other.major()) &&
               (this->minor() == other.minor()) &&
               (this->patch() == other.patch());
    }

    bool operator !=(const version &other) const {
        return !(*this == other);
    }
};

inline dpp::version get_thisversion() {
    return dpp::version(DXX_VERSION_MAJOR,
                        DXX_VERSION_MINOR,
                        DXX_VERSION_PATCH);
}

NAMESPACE_DPP_END

#endif // !_DPP_VERSIONDEF_HPP