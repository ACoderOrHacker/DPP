/*
 Array Manager
*/
#ifndef _ARRAY_H
#define _ARRAY_H
#include <stdint.h>
#include <vector>

template<typename T> class Array {
	public:
		Array() {
			array = new std::vector<T>();
		}
		Array(T fill_data) {
			array->fill(fill_data);
		}
		T operator [](uint32_t n) {
			return (array->at(n));
		}
		void write(uint32_t n, T data) {
			if(array->size() < n) {
				array->resize(n);
			}
			array->insert(array->begin() + n, data);
		}
		size_t size() {
			return array->size();
		}
		auto end() {
			return array->end();
		}
	private:
		std::vector<T> *array;
};

#endif // !_ARRAY_H
