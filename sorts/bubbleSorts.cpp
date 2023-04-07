#include <vector>

/// сортировка пузырьком
void bubbleSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    *oper += 2;
    for (int i = 0; i + 1 < n; ++i) {
        *oper += 3;
        for (int j = 0; j + 1 < n - i; ++j) {
            *oper += 8;
            if (array[j + 1] < array[j]) {
                *oper += 9;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/// сортировка пузырьком с условием Айверсона (1)
void bubbleSortIverson1(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    bool condition = true;
    *oper += 3;
    for (int i = 0; condition; ++i) {
        condition = false;
        *oper += 2;
        for (int j = 0; j < n - i - 1; ++j) {
            *oper += 7;
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                condition = true;
                *oper += 10;
            }
        }
    }
}

/// сортировка пузырьком с условием Айверсона (1 и 2)
void bubbleSortIverson12(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    bool condition = true;
    int old_bound = n - 1;
    *oper += 4;
    for (int i = 0; condition; ++i) {
        condition = false;
        int new_bound = n - 1 - i;
        *oper += 4;
        for (int j = 0; j < old_bound; ++j) {
            *oper += 6;
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                condition = true;
                new_bound = j;
                *oper += 11;
            }
        }
        old_bound = new_bound;
        ++*oper;
    }
}
