#ifndef _SET_H
#define _SET_H
#include <deque>
template<typename Key, typename Value> class Set {
    public:
        std::deque<Key> dat1;
        std::deque<Value> dat2;
        void PushData(Key key, Value value) {
            dat1.push_back(key);
            dat2.push_back(value);
        }
        void PopData(Key *key, Value *value) {
            key = &(*(dat1.begin()));
            value = &(*(dat2.begin()));
            dat1.pop_front();
            dat2.pop_front();
        }
		Key getKey(typename std::deque<Key>::iterator key_it) {
		    return (*key_it);
		}
		Value getValue(typename std::deque<Value>::iterator value_it) {
		    return (*value_it);
		}
		size_t size() {
		    return dat1.size();
		}
        typename std::deque<Key> getKeyList() {
            return dat1;
        }
        typename std::deque<Value> getValueList() {
            return dat2;
        }
};

#endif // !_SET_H
