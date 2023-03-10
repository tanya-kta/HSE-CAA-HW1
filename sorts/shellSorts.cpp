#include <vector>

/// сортировка Шелла
void shellSort(std::vector<int>& array) {
    int n = array.size();
    for (int d = n >> 1; d != 0; d >>= 1) {
        for (int i = d; i < n; ++i) {
            for (int j = i; j >= d && array[j] < array[j - d]; j -= d) {
                int temp = array[j];
                array[j] = array[j - d];
                array[j - d] = temp;
            }
        }
    }
}

/// сортировка Шелла с последовательностью Циура
void ciuraShellSort(std::vector<int>& array) {
    int n = array.size();
    std::vector<int> sequence = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    for (int d : sequence) {
        for (int i = d; i < n; ++i) {
            for (int j = i; j >= d && array[j] < array[j - d]; j -= d) {
                int temp = array[j];
                array[j] = array[j - d];
                array[j - d] = temp;
            }
        }
    }
}