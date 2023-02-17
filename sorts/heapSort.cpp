#include <vector>

/// нормализация кучи
void heapify(std::vector<int>& array, int n, int i) {
    for (;;) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && array[left] > array[largest]) {
            largest = left;
        }

        if (right < n && array[right] > array[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        i = largest;
    }
}

/// пирамидальная сортировка
void heapSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(array, array.size(), i);
    }
    for (int i = n - 1; i >= 0; --i) {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        heapify(array, i, 0);
    }
}