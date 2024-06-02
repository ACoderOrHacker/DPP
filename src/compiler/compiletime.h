#ifndef _COMPILETIME
#define _COMPILETIME
#include <stddef.h>
#include "vm.hpp"
/*
class Convert {
public:
	Convert(Heap<struct _Convert> *_list) {
		this->convertList = _list;
	}

	bool canConvert(uint32_t from, uint32_t to) {
		for(auto it : *convertList) {
			if(it.src_type == from && it.to_type == to) {
				return true;
			}
		}

		return false;
	}
private:
	Heap<struct _Convert> *convertList;
};*/
#endif // !_COMPILETIME
