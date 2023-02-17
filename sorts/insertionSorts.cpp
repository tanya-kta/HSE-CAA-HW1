#include <vector>

/// сортировка простыми вставками
void simpleInsertionSort(std::vector<int>& array) {
    int n = array.size();
    for (int j = 1; j < n; ++j) {
        int key = array[j];
        int i = j - 1;
        while (i >= 0 and array[i] > key) {
            array[i + 1] = array[i];
            --i;
        }
        array[i + 1] = key;
    }
}

/// сортировка простыми вставками
void binaryInsertionSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int l = -1, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (array[mid] >= array[i]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        for (int m = j; m > l; --m) {
            int temp = array[m];
            array[m] = array[m + 1];
            array[m + 1] = temp;
        }
    }
}
