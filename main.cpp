#include <iostream>
#include <vector>
#include "sorts/bubbleSorts.cpp"
#include "sorts/insertionSorts.cpp"
#include "sorts/selectionSort.cpp"
#include "sorts/countingSort.cpp"
#include "sorts/radixSort.cpp"
#include "sorts/quickSort.cpp"
#include "sorts/mergeSort.cpp"
#include "sorts/heapSort.cpp"
#include "sorts/shellSorts.cpp"


int main() {
    std::vector<int> v = {5, 4, 3, 4, 1};
    bubbleSort(v);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
    }
    return 0;
}
