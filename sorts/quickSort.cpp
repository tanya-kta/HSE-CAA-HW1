#include <vector>

typedef std::vector<int>::iterator Iter;

/// быстрая сортировка с первым опорным элементом
void quickSortHelper(Iter begin, Iter end) {
    int m = *begin;
    int n = end - begin;
    int l = 0, r = n - 1;
    while (l < r) {
        while (*(begin + r) >= m && l < r) {
            r--;
        }
        while (m > *(begin + l) && l < r) {
            l++;
        }
        int temp = *(begin + l);
        *(begin + l) = *(begin + r);
        *(begin + r) = temp;
    }

    if (l > 1) {
        quickSortHelper(begin, begin + l);
    }
    if (l < n - 2) {
        quickSortHelper(begin + l + 1, begin + n - l);
    }
}

/// вызов быстрой сортировки
void quickSort(std::vector<int>& array) {
    quickSortHelper(array.begin(), array.end());
}