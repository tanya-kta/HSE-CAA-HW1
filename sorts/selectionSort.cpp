#include <vector>

/// сортировка выбором
void selectionSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    *oper += 2;
    for (int i = 0; i < n - 1; ++i) {
        int mx = i;
        *oper += 5;
        for (int j = i + 1; j < n; ++j) {
            if (array[mx] > array[j]) {
                mx = j;
                ++*oper;
            }
            *oper += 5;
        }
        int temp = array[i];
        array[i] = array[mx];
        array[mx] = temp;
        *oper += 7;
    }
}
