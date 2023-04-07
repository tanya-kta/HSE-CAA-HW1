#include <vector>

/// нормализация кучи
void heapify(std::vector<int>& array, int n, int i, uint64_t *oper) {
    for (;;) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        *oper += 10;
        if (left < n && array[left] > array[largest]) {
            largest = left;
            ++*oper;
        }

        if (right < n && array[right] > array[largest]) {
            largest = right;
            ++*oper;
        }
        *oper += 6;
        if (largest == i) {
            break;
        }
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        i = largest;
        *oper += 8;
    }
}

/// пирамидальная сортировка
void heapSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        *oper += 2;
        heapify(array, array.size(), i, oper);
    }
    *oper += 3;
    for (int i = n - 1; i >= 0; --i) {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        *oper += 9;
        heapify(array, i, 0, oper);
    }
}