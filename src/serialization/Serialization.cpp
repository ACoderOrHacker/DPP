#include "Serialization.hpp"

template<typename T>
T *dpp::serialize::load(std::istream istream) {
    boost::archive::binary_iarchive archive(istream);
    T *object = new T;
    archive >> object;

    return object;
}

template<typename T>
STATUS dpp::serialize::save(std::ostream &ifs, T *object) {
    boost::archive::binary_oarchive archive(ifs);

    archive << object;

    return STATUS_SUCCESS;
}