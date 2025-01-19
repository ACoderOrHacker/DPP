/**
 * @file array.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief D++ Array Module
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef _ARRAY_H
#define _ARRAY_H
#include <cstdint>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cereal/types/vector.hpp>
#include "macros.hpp"

/**
 * @brief The array class container
 *
 * @tparam T the array contains type
 */
template<typename T> class Array {
public:
    Array() = default;
    ~Array() = default;

    /**
        * @brief Construct a new Array object and fill it with 'fill_data'
        *
        * @param fill_data the data to fill
        */
    explicit Array(const T &fill_data) {
        array.fill(fill_data);
    }

    /**
        * @brief Get the Container object
        *
        * @return std::vector<T> & the contaner
        */
    auto &getContainer() const {
        return array;
    }

    /**
        * @brief get the data at index 'n'
        *
        * @param n the index to array
        * @return T & the data
        */
    T &operator [](uint32_t n) const {
        return (array.at(n));
    }

    /**
        * @brief copy the data from other array
        *
        * @param data the other array
        * @return Array<T> &
        */
    Array<T> &operator =(const Array<T> &data) {
        std::copy(data.begin(), data.end(), std::back_inserter(array));

        return *this;
    }

    /**
        * @brief write the data to an index
        *
        * @param n the data index
        * @param data the data to write
        */
    void write(uint32_t n, const T &data) {
        if(array.size() < n) {
            array.resize(n);
        }
        array.insert(array.begin() + n, data);
    }

    /**
        * @brief write the data to an index
        *
        * @param n the data index
        * @param data the data to write
        * @deprecated bool is not used
        */
    void write(uint32_t n, const T &&data, bool) {
        if(array.size() < n) {
            array.resize(n);
        }
        array.insert(array.begin() + n, std::move(data));
    }

    /**
        * @brief insert a data to the array
        *
        * @param data the data to insert
        */
    void write(const T &data) {
        array.resize(array.size());

        array.insert(array.end(), data);
    }

    /**
        * @brief rewrite an index with another data
        *
        * @param n the index to rewrite
        * @param data the data to write
        */
    void rewrite(uint32_t n, T data) {
        if(array.size() <= n) {
            array.resize(n + 1);
        }
        array.at(n) = data;
    }

    /**
        * @brief find and remove a data from the array
        *
        * @param data the data to remove
        */
    void remove(const T &data) {
        std::ignore = std::remove(array.begin(), array.end(), data);
    }

    /**
        * @brief get size from the array
        *
        * @return size_t the size of the array
        */
    [[nodiscard]] size_t size() const {
        return array.size();
    }

    /**
        * @brief get the begin iterator
        *
        * @return std::vector<T>::iterator the begin iterator
        */
    auto begin() const {
        return array.begin();
    }

    /**
        * @brief get the end iterator
        *
        * @return std::vector<T>::iterator the end iterator
        */
    auto end() const {
        return array.end();
    }

    /**
        * @brief remove the last element of the array
        *
        * @return void
        */
    void pop() {
        array.pop_back();
    }
private:
    /**
     * @brief the array. it storge the data
     *
     */
    std::vector<T> array;

Dpp_SERIALIZE(Dpp_NVP(array))
};

#endif // !_ARRAY_H
