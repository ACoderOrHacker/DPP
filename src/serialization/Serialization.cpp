#include "Serialization.hpp"

template<typename T> T *dpp::seralization::load(std::istream istream) {
    boost::archive::binary_iarchive archive(istream);
    T *object = new T;
    archive >> object;

    return Object;
}

template<typename T> STATUS dpp::seralization::save(std::ostream &ifs, T *object) {
    boost::archive::binary_oarchive archive(ofs);

    archive << object;

    return STATUS_SUCCESS;
}