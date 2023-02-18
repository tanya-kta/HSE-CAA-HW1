#include <vector>

typedef std::vector<int>::iterator Iter;

/// быстрая сортировка с первым опорным элементом
void quickSortHelper(Iter begin, Iter end) {
    int m = *begin;
    int n = end - begin;
    int l = 0, r = n - 1;
    if (n == 1) {
        return;
    }
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

    if (l > 0) {
        quickSortHelper(begin, begin + l + 1);
    }
    if (l < n - 1) {
        quickSortHelper(begin + l + 1, end);
    }
}

/// вызов быстрой сортировки
void quickSort(std::vector<int>& array) {
    quickSortHelper(array.begin(), array.end());
}