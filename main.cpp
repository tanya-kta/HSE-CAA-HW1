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
#include "utils.cpp"
#include "generate.cpp"

std::vector<void (*)(std::vector<int>&)> sorts({
    bubbleSort, bubbleSortIverson1, bubbleSortIverson12,
    countingSort, heapSort, simpleInsertionSort, binaryInsertionSort,
    mergeSort, quickSort, radixSort, selectionSort,
    shellSort, ciuraShellSort
});
std::vector<std::string> sort_names({
    "BubbleSort", "BubbleSortIverson1", "BubbleSortIverson12",
    "CountingSort", "HeapSort", "SimpleInsertionSort", "BinaryInsertionSort",
    "MergeSort", "QuickSort", "RadixSort", "SelectionSort",
    "ShellSort", "CiuraShellSort"
});
std::vector<std::vector<int> (*)(int)> generators({
    smallRangeArray, largeRangeArray, almostSortedArray, decreasingArray
});
std::vector<std::string> gen_names({
    "random_small_range", "random_large_range", "almost_sorted", "decreasing"
});


int main() {
    std::vector<int> v = {5, 4, 3, 4, 1};
    bubbleSort(v);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
    }
    return 0;
}
