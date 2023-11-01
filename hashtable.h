#pragma once
#include <memory>

template<class keyType, class elemType>
struct hashentry {
    const keyType key;
    const std::unique_ptr<elemType> value;
};
template<class keyType, class elemType>
class hashtable {
public:
    hashtable(int buckets);
    ~hashtable();
    const std::unique_ptr<elemType> &get(const keyType &key) const ;
    bool set(const keyType &key, const elemType &value);
private:
    hashentry<keyType, elemType> *buckets;
    int numBuckets;
};
