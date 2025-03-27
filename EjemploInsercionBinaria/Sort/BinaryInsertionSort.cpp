#include "BinaryInsertionSort.hpp"

template <typename T>
void BinaryInsertionSort<T>::sort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

template <typename T>
int BinaryInsertionSort<T>::binarySearch(vector<T>& arr, T key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid + 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

template class BinaryInsertionSort<Order>;