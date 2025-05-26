#include <iostream>
#include <cstring>

// Generic template function
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Specialization for char*
template <>
void swapValues<char*>(char*& a, char*& b) {
    char* temp = a;
    a = b;
    b = temp;
}

int main() {
    // Example with integers
    int x = 10, y = 20;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapValues(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    // Example with char*
    char* str1 = (char*)"Hello";
    char* str2 = (char*)"World";
    std::cout << "\nBefore swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    swapValues(str1, str2);
    std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    return 0;
}

