#include <vector>
#include <iostream>

void printArray(std::vector<int>& array) {
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

bool checker(std::vector<int>& original, std::vector<int>& sorted) {
    if (original.size() != sorted.size()) {
        return false;
    }
    int n = original.size();
    for (int i = 0; i < n - 1; ++i) {
        if (sorted[i] > sorted[i + 1]) {
            std::cout << "Sorter's output array is not sorted in non-decreasing order.\n\n";
            return false;
        }
    }

    std::vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < n && !found; ++j) {
            if (!used[j] && original[i] == sorted[j]) {
                found = true;
                used[j] = true;
            }
        }
        if (!found) {
            std::cout << "Sorted array does not contain some elements from the original array\n\n";
            return false;
        }
    }
    return true;
}
