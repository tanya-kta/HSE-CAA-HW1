#include <vector>

/// сортировка простыми вставками
void simpleInsertionSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    *oper += 2;
    for (int j = 1; j < n; ++j) {
        int key = array[j];
        int i = j - 1;
        *oper += 6;
        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            --i;
            *oper += 7;
        }
        array[i + 1] = key;
        *oper += 3;
    }
}

/// сортировка простыми вставками
void binaryInsertionSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    *oper += 2;
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int l = -1, r = i;
        *oper += 6;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (array[mid] >= array[i]) {
                r = mid;
            } else {
                l = mid;
            }
            *oper += 8;
        }
        for (int m = j; m > l; --m) {
            int temp = array[m];
            array[m] = array[m + 1];
            array[m + 1] = temp;
            *oper += 11;
        }
    }
}
