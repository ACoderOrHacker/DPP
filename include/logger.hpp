
#include <fstream>
#include <iostream>
#include "macros.hpp"

NAMESPACE_DPP_BEGIN

class logger {
public:
    logger() : stream(&std::cout) {}

    explicit logger(std::ostream &ostream) : stream(&ostream) {}

    template<typename T>
    logger &operator <<(const T &data) {
        *stream << data;
        return *this;
    }

    template<typename T>
    logger &write_tofile(const T &data) {
        if (dynamic_cast<std::ofstream *>(stream) != nullptr) {
            return (*this << data);
        }
    }


    template<typename T>
    logger &write_toconsole(const T &data) {
        if (stream == &std::cout || stream == &std::cerr || stream == &std::clog) {
            return (*this << data);
        }
    }
private:
    std::ostream *stream;
};

NAMESPACE_DPP_END