#include <vector>

/// сортировка Шелла
void shellSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    *oper += 2;
    for (int d = n >> 1; d != 0; d >>= 1) {
        *oper += 3;
        for (int i = d; i < n; ++i) {
            *oper += 3;
            for (int j = i; j >= d && array[j] < array[j - d]; j -= d) {
                int temp = array[j];
                array[j] = array[j - d];
                array[j - d] = temp;
                *oper += 16;
            }
        }
    }
}

/// сортировка Шелла с последовательностью Циура
void ciuraShellSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    std::vector<int> sequence = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    *oper += 2;
    for (int d : sequence) {
        *oper += 3;
        for (int i = d; i < n; ++i) {
            *oper += 3;
            for (int j = i; j >= d && array[j] < array[j - d]; j -= d) {
                int temp = array[j];
                array[j] = array[j - d];
                array[j - d] = temp;
                *oper += 16;
            }
        }
    }
}