 /*
* D++ Heap Manager
* Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _HEAP_H
#define _HEAP_H
#include <cstdint>
#include <deque>
#include <cereal/types/deque.hpp>
#include "macros.hpp"

#define to_iterator(list, index) (list.begin() + index)

/*
* Base Heap
*/
template<typename T, typename container = std::deque<T>> class Heap {
	public:
		Heap() = default;
		explicit Heap(container &c) {
			Data = c;
		}
        Heap(std::initializer_list<T> l) {
            Data = l;
        }
        Heap(typename container::iterator _start, typename container::iterator _end) {
            Data = container(_start, _end);
        }
    public:
        container Data; // Data for heap
        typename container::iterator it;

		void clear() {
			Data.clear();
		}
        void PushData(T data) {
            Data.push_front(data);
        }
        void PushEnd(T data) {
            Data.push_back(data);
        }
        void ResetData(uint32_t index, T data) {
            it = to_iterator(Data, index);
            Remove();

            it = to_iterator(Data, index);
            ItSetData(it, data);
            it = Data.begin();
        }
        void SetData(uint32_t index, T data) {
        	Data.insert(to_iterator(Data, index), data);
		}
		void ItSetData(typename container::iterator index, T data) {
        	Data.insert(index, data);
		}
        T PopData() {
            T data = Data.back();
            Data.pop_back();
            return (data);
        }
        T PopFront() {
            T data = Data.front();
            Data.pop_front();
            return (data);
        }
        bool isEmpty() {
            return (Data.empty());
        }
        size_t size() {
        	return (Data.size());
		}
		typename container::iterator begin() {
		    return (Data.begin());
		}
		typename container::iterator end() {
		    return (Data.end());
		}
		T GetData(uint32_t i) {
			return (Data[i]);
		}
		T GetAndDeleteData(uint32_t i) {
			T dat = Data[i];
			Data.erase(this->begin()+i);
			return (dat);
		}
		bool inheap(T data) {
		    it = find(Data.begin(), Data.end(), data);
		    if(it != Data.end()) {
                return true;
		    } else {
		        return false;
		    }
		}
		void Delete() {
		    Data.erase(it);
		    delete (*it);
		}
        void Remove() {
            Data.erase(it);
        }
		void Delete(T data) {
		    auto it = find(Data.begin(), Data.end(), data);
		    if(it != Data.end()) {
                this->Delete(it);
		    }
		}
		void merge(Heap<T> data) {
		    Data.insert(Data.end(), data.begin(), data.end());
		}
		void Delete(typename container::iterator _start, typename container::iterator _end) {
		    Data.erase(_start, _end);
		}
		void Delete(typename container::iterator _it) {
		    Data.erase(_it);
		}
		container getContainer() {
			return Data;
		}

		bool operator ==(Heap<T> data) {
			return (this->Data == data.Data);
		}
		Heap<T> &operator =(container &c) {
			Data = c;

            return *this;
		}
        Heap<T> get(uint32_t start, uint32_t end) {
            return (Heap<T>(Data.begin()+start, Data.begin()+end));
        }

Dpp_SERIALIZE(Dpp_NVP(Data))
};
#endif // !_HEAP_H
