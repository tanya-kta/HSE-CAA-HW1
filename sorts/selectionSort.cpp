#include <vector>

/// сортировка выбором
void selectionSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        int max = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[max] > array[j]) {
                max = j;
            }
        }
        std::swap(array[i], array[max]);
    }
}
