/*
 * АиСД-2, 2023, задание 5
 * Кадыкова Татьяна Алексеевна
 * БПИ213
 * CLion
 * Сделаны изменения времени и количества операцией всех 13 сортировок для всех массивов и запись их в таблицу
 */


#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

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

std::vector<void (*)(std::vector<int>&, uint64_t *)> sorts({
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
    "RandomSmallRange", "RandomLargeRange", "AlmostSorted", "Decreasing"
});

std::vector<uint64_t> computing_times(sorts.size() * generators.size());
std::vector<uint64_t> operations_count(sorts.size() * generators.size(), 0);

/// вычисляет значения времени для всех комбинаций сортировок и методов генерации массива фиксированного размера
void calculateComputingTimes(int size) {
    std::vector<int> original, to_sort;
    for (int k = 0; k < generators.size(); ++k) {
        original = generators[k](size);
        for (int j = 0; j < sorts.size(); ++j) {
            to_sort = original;
            auto start = std::chrono::high_resolution_clock::now();
            sorts[j](to_sort, &operations_count[k * sorts.size() + j]);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            if (!checker(original, to_sort)) {
                std::cout << "failed to sort array size " << size << " generated " << gen_names[k] <<
                    " using " << sort_names[j] << "\nOriginal array:";
                printArray(original);
                std::cout << "Sorted array: ";
                printArray(to_sort);
            }
            computing_times[k * sorts.size() + j] =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        }
    }
}

std::string getNames() {
    std::string first_row = "Array sizes";
    for (int k = 0; k < generators.size(); ++k) {
        for (int j = 0; j < sorts.size(); ++j) {
            first_row.append(";" + gen_names[k] + " & " + sort_names[j]);
        }
    }
    first_row.append("\n");
    return first_row;
}

void fillTable(std::ofstream *stream_time, std::ofstream *stream_oper, int size) {
    calculateComputingTimes(size);
    std::string table_row = std::to_string(size);
    for (auto comp_time : computing_times) {
        table_row.append(";" + std::to_string(comp_time));
    }
    table_row.append("\n");
    *stream_time << table_row;

    table_row = std::to_string(size);
    for (auto operations : operations_count) {
        table_row.append(";" + std::to_string(operations));
    }
    table_row.append("\n");
    *stream_oper << table_row;
}

void smallArraysTest() {
    std::ofstream table("/mnt/c/Users/tanya/Documents/CLionProjects/HSE-HW1/smallSizesTimes.csv");
    std::ofstream table_oper("/mnt/c/Users/tanya/Documents/CLionProjects/HSE-HW1/smallSizesOper.csv");
    table << getNames();
    table_oper << getNames();
    for (int size = 50; size <= 300; size += 50) {
        fillTable(&table, &table_oper, size);
    }
    table.close();
    table_oper.close();
}

void largeArraysTest() {
    std::ofstream table("/mnt/c/Users/tanya/Documents/CLionProjects/HSE-HW1/bigSizesTimes.csv");
    std::ofstream table_oper("/mnt/c/Users/tanya/Documents/CLionProjects/HSE-HW1/bigSizesOper.csv");
    table << getNames();
    table_oper << getNames();
    for (int size = 100; size <= 4100; size += 100) {
        fillTable(&table, &table_oper, size);
    }
    table.close();
    table_oper.close();
}


int main() {
    smallArraysTest();
    largeArraysTest();
    return 0;
}
