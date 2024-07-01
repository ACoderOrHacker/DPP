#include <boost/archive/basic_archive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include "struct.hpp"

namespace dpp {
    namespace serialization {
        template<typename T> T *load(std::istream);

        template<typename T> STATUS save(std::ostream &, T *);
    }
}
