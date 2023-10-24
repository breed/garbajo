#include "myarraylist.h"
#include <iostream>
using namespace std;

template <class elemType> arrayListType<elemType>::arrayListType(int size):maxSize(size), length(0) {
    list = new elemType[size];
}

template <class elemType> arrayListType<elemType>::~arrayListType() {
    delete[] list;
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType &insertItem) {
    /*
    if (length == maxSize) {
        maxSize *= 2;
        auto newList = new elemType[maxSize];
        for (int i = 0; i < length; i++) {
            newList[i] = list[i];
        }
        auto oldList = list;
        list = newList;
        delete[] oldList;
    }
    */
    if (isFull(true)) return;
    list[length++] = insertItem;
}

template <class elemType>
bool arrayListType<elemType>::isFull(bool printMessage) const {
    if (length == maxSize) {
        if (printMessage) cout << "list is full!" << endl;
        return true;
    }
    return false;
}



template <class elemType> void arrayListType<elemType>::print() const {
    cout << "len " << length << " max size" << maxSize << endl;
    int i = 0;
    for (; i < 10 && i < length; i++) {
        cout << "[" << i << "] " << list[i] << endl;
    }
    if (length - i > 10) {
        cout << "..." << endl;
        i = length - i;
    }
    for (; i < length; i++) {
        cout << "[" << i << "] " << list[i] << endl;
    }
}
int main() {
    auto mylist = arrayListType<int>();
    for (int i = 0; i < 2000000; i++) {
        mylist.insertEnd(i*100 + 17);
    }

    mylist.print();
}