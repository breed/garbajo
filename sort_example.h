
#pragma once


template <class T>
class arrayListType {
public:
    arrayListType(T *a, int s): size(s) {
        array = new T[s];
        for (int i = 0; i < s; i++) array[i] = a[i];
    }
    ~arrayListType() {
        delete[](array);
    }
    void selectionSort(bool do_print = false);
    void insertionSort(bool do_print = false);
    void shellSort(bool do_print = false);
    void quickSort(bool do_print = false);
    int minLocation(int first = 0, int last = -1) const;
    void print() const;
    void swap(int first, int second);
    void bubble(int i, int inc);
    int partition(int first, int last);
    void innerQuickSort(bool do_print, int first, int last);
private:
    T *array;
    const int size;

};

