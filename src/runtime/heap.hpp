 /*
* D++ Heap Manager
* Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _HEAP_H
#define _HEAP_H
#include <stdint.h>
#include <deque>
#include <algorithm>

#define to_iterator(list, index) (list.begin() + index)

/*
* Base Heap
*/
template<typename T, typename container = std::deque<T>> class Heap {
	public:
		Heap() {

		}
		Heap(container &c) {
			Data = c;
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
            T data = &(*(Data.front()+1));
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
		void merge(Heap<T> *data) {
		    Data.insert(Data.end(), data->begin(), data->end());
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
		void operator =(container &c) {
			Data = c;
		}
};
#endif // !_HEAP_H
