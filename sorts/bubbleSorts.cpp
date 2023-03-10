#include <vector>

/// сортировка пузырьком
void bubbleSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < n - i; ++j) {
            if (array[j + 1] < array[j]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/// сортировка пузырьком с условием Айверсона (1)
void bubbleSortIverson1(std::vector<int>& array) {
    int n = array.size();
    bool condition = true;
    for (int i = 0; condition; ++i) {
        condition = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                condition = true;
            }
        }
    }
}

/// сортировка пузырьком с условием Айверсона (1 и 2)
void bubbleSortIverson12(std::vector<int>& array) {
    int n = array.size();
    bool condition = true;
    int old_bound = n - 1;
    for (int i = 0; condition; ++i) {
        condition = false;
        int new_bound = n - 1 - i;
        for (int j = 0; j < old_bound; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                condition = true;
                new_bound = j;
            }
        }
        old_bound = new_bound;
    }
}
