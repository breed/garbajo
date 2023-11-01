#include <iostream>
using namespace std;
#include "hashtable.h"

template<class keyType, class elemType>
hashtable<keyType, elemType>::hashtable(int buckets): numBuckets(buckets) {
    buckets = new hashentry<keyType, elemType>[buckets];
}

template<class keyType, class elemType>
hashtable<keyType, elemType>::~hashtable() {
    delete[](buckets);
}

template<class keyType, class elemType>
const unique_ptr<elemType> &hashtable<keyType, elemType>::get(const keyType &key) const {
    int hash = hashCode(key) % numBuckets;
    if (buckets[hash].key == key) return buckets[hash].value;
    static unique_ptr<elemType> empty;
    return empty;
}

int hashCode(string s) {
    int hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash = hash << 1 + s[i];
    }
    return hash;
}

template<class keyType, class elemType>
bool hashtable<keyType, elemType>::set(const keyType &key, const elemType &value) {
    int hash = hashCode(key) % numBuckets;
    if (buckets[hash].value) {
        cout << "no room for " << key << endl;
        return false;
    }
    buckets[hash].value.reset(&value);
}

int main() {
    hashtable<string, int> table(10);
    table.set("ben", 1);
    table.set("amy", 2);
    table.set("fred", 3);
    table.set("kevin", 4);
    table.set("ann", 5);
    table.set("tanya", 7);
}