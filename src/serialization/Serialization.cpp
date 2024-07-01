#include "Serialization.hpp"

template<typename T>
T *dpp::serialization::load(std::istream istream) {
    boost::archive::binary_iarchive archive(istream);
    T *object = new T;
    archive >> object;

    return object;
}

template<typename T>
STATUS dpp::serialization::save(std::ostream &ifs, T *object) {
    boost::archive::binary_oarchive archive(ofs);

    archive << object;

    return STATUS_SUCCESS;
}