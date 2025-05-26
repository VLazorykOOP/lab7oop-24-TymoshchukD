#include <iostream>
#include <cstring>

// Generic template for sorting (Bubble Sort)
template <typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Specialization for const char* sorting
template <>
void sortArray<const char*>(const char* arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                const char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Generic template for binary search
template <typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

// Specialization for const char* binary search
template <>
int binarySearch<const char*>(const char* arr[], int size, const char* key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], key);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

int main() {
    // Example with integers
    int nums[] = { 9, 1, 5, 3, 7 };
    int sizeNums = sizeof(nums) / sizeof(nums[0]);
    sortArray(nums, sizeNums);
    int index = binarySearch(nums, sizeNums, 5);
    std::cout << "Index of 5: " << index << std::endl;

    // Example with const char*
    const char* words[] = { "apple", "orange", "banana", "grape", "kiwi" };
    int sizeWords = sizeof(words) / sizeof(words[0]);
    sortArray(words, sizeWords);
    int wordIndex = binarySearch(words, sizeWords, "banana");
    std::cout << "Index of 'banana': " << wordIndex << std::endl;

    return 0;
}
