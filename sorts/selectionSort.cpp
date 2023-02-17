#include <vector>

/// сортировка выбором
void selectionSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        int mx = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[mx] > array[j]) {
                mx = j;
            }
        }
        int temp = array[i];
        array[i] = array[mx];
        array[mx] = temp;
        std::swap(array[i], array[mx]);
    }
}
