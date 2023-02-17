#include <iostream>
#include <vector>
#include <chrono>
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


/// вычисляет значения времени для всех комбинаций сортировок и методов генерации массива фиксированного размера
std::vector<uint64_t> tester(int size) {
    std::vector<uint64_t> result ({static_cast<uint64_t>(size)});
    for (int k = 0; k < generators.size(); ++k) {
        std::vector<int> original = generators[k](size);
        for (int j = 0; j < sorts.size(); ++j) {
            std::vector<int> to_sort = original;
            auto start = std::chrono::high_resolution_clock::now();
            sorts[j](to_sort);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            if (!checker(original, to_sort)) {
                std::cout << "failed to sort array size " << size << " generated " << gen_names[k] <<
                    " using " << sort_names[j] << "\nOriginal array:";
                printArray(original);
            }
            result.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count());
        }
    }
    return result;
}


int main() {
    std::vector<int> v = {5, 4, 3, 4, 1};
    bubbleSort(v);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
    }
    return 0;
}
