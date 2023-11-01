#include "sort_example.h"

#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

template <class T>
int arrayListType<T>::minLocation(int first, int last) const {
    if (last == -1) last = size;
    int smallest = first;
    for (int i = first + 1; i < last; i++) {
        if (array[i] < array[smallest]) smallest = i;
    }
    return smallest;
}

template <class T>
void arrayListType<T>::swap(int first, int second) {
    T temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}


template<class T>
void arrayListType<T>::bubble(int i, int inc) {
    if (i - inc >= 0 && array[i] < array[i - inc]) {
        int bubble_index = i;
        T last = array[i];
        while (bubble_index - inc >= 0 && last < array[bubble_index - inc]) {
            array[bubble_index] = array[bubble_index - inc];
            bubble_index -= inc;
        }
        array[bubble_index] = last;
    }
}

template<class T>
int arrayListType<T>::partition(int first, int last) {
    // NOTE: last is inclusive!!!
    int mid = (first + last) / 2;
    T pivot = array[mid];
    swap(first, mid);
    int smallIndex = first;
    for (int i = first+1; i <= last; i++) {
        if (array[i] < pivot) swap(++smallIndex, i);
    }
    swap(first, smallIndex);
    return smallIndex;
}

template <class T>
void arrayListType<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void arrayListType<T>::selectionSort(bool do_print) {
    if (do_print) {std::cout << "Selection sort: " << endl; print(); }
    for (int i = 0; i < size-1; i++) {
        int smallest = minLocation(i, size);
        if (smallest != i) swap(smallest, i);
        if (do_print) print();
    }
}

template <class T>
void arrayListType<T>::insertionSort(bool do_print) {
    if (do_print) {std::cout << "Insertion sort: " << endl; print(); }

    for (int i = 1; i < size-1; i++) {
        bubble(i, 1);
        if (do_print) print();
    }
}

template <class T>
void arrayListType<T>::shellSort(bool do_print) {
    if (do_print) {std::cout << "Shell sort: " << endl; print(); }

    int inc;
    for (inc = 1; inc < (size-1)/9; inc = 3*inc +1);

    for (; inc > 0; inc /= 3) {
        for (int i = inc; i < size; i++) {
            bubble(i, inc);
            if (do_print) { cout << inc << ": "; print(); }
        }
    }
}

template <class T>
void arrayListType<T>::innerQuickSort(bool do_print, int first, int last) {
    if (first < last) {
        int pivot = partition(first, last);
        if (do_print) { cout << first << "-" << last << " " << array[pivot] << "[" << pivot << "] "; print(); }
        innerQuickSort(do_print, first, pivot-1);
        innerQuickSort(do_print, pivot+1, last);
    }
}

template <class T>
void arrayListType<T>::quickSort(bool do_print) {
    if (do_print) {std::cout << "Quick sort: " << endl; print(); }
    innerQuickSort(do_print, 0, size-1);
}

#define LOTS_OF_NUMS 200000
int main() {
    int lots_of_nums[LOTS_OF_NUMS];
    for (int i = 0; i < LOTS_OF_NUMS; i++) {
        lots_of_nums[i] = (i + 1970) % 2048;
    }
    int nums[] = {  1, 22, 4, 0, 8, 8, 6, 7, 5, 3, 0, 9, 3, 1, 4, 1, 5, 9, 2, 7};
    {
        arrayListType<int> list(nums, sizeof(nums) / sizeof(nums[0]));
        list.selectionSort(true);

        arrayListType<int> lots(lots_of_nums, LOTS_OF_NUMS);
        auto start = high_resolution_clock::now();
        lots.selectionSort();
        duration<double, milli> duration = high_resolution_clock::now() - start;
        cout << "selection sort took " << duration.count() << endl;

    }
    {
        arrayListType<int> list(nums, sizeof(nums) / sizeof(nums[0]));
        list.insertionSort(true);
        arrayListType<int> lots(lots_of_nums, LOTS_OF_NUMS);
        auto start = high_resolution_clock::now();
        lots.insertionSort();
        duration<double, milli> duration = high_resolution_clock::now() - start;
        cout << "insertion sort took " << duration.count() << endl;
    }
    {
        arrayListType<int> list(nums, sizeof(nums) / sizeof(nums[0]));
        list.shellSort(true);
        arrayListType<int> lots(lots_of_nums, LOTS_OF_NUMS);
        auto start = high_resolution_clock::now();
        lots.shellSort();
        duration<double, milli> duration = high_resolution_clock::now() - start;
        cout << "shell sort took " << duration.count() << endl;
    }

    {
        arrayListType<int> list(nums, sizeof(nums) / sizeof(nums[0]));
        list.quickSort(true);
        arrayListType<int> lots(lots_of_nums, LOTS_OF_NUMS);
        auto start = high_resolution_clock::now();
        //lots.quickSort();
        duration<double, milli> duration = high_resolution_clock::now() - start;
        cout << "quick sort took " << duration.count() << endl;
    }
    return 0;
}