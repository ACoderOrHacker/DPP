/*
 Array Manager
*/
#ifndef _ARRAY_H
#define _ARRAY_H
#include <cstdint>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T> class Array {
	public:
		Array() {
			array = new std::vector<T>();
		}
		explicit Array(T fill_data) {
			array->fill(fill_data);
		}
        auto *getContainer() {
            return array;
        }
		T operator [](uint32_t n) {
			return (array->at(n));
		}
        void operator =(Array<T> data) {
            std::copy(data.begin(), data.end(), std::back_inserter(*array));
        }
		void write(uint32_t n, T data) {
			if(array->size() < n) {
				array->resize(n);
			}
			array->insert(array->begin() + n, data);
		}
        void write(T data) {
            array->resize(array->size());

            array->insert(array->end(), data);
        }
        void rewrite(uint32_t n, T data) {
            if(array->size() <= n) {
				array->resize(n + 1);
			}
            array->at(n) = data;
        }
        void remove(T data) {
            std::ignore = std::remove(array->begin(), array->end(), data);
        }
		size_t size() {
			return array->size();
		}
        auto begin() {
            return array->begin();
        }
		auto end() {
			return array->end();
		}
	private:
		std::vector<T> *array;
};

#endif // !_ARRAY_H
