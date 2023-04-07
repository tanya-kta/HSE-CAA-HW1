#include <vector>

typedef std::vector<int>::iterator Iter;

/// быстрая сортировка с первым опорным элементом
void quickSortHelper(Iter begin, Iter end, uint64_t *oper) {
    int m = *begin;
    int n = end - begin;
    int l = 0, r = n - 1;
    *oper += 8;
    if (n == 1) {
        return;
    }
    while (l < r) {
        *oper += 6;
        while (*(begin + r) >= m && l < r) {
            r--;
            *oper += 6;
        }
        *oper += 5;
        while (m > *(begin + l) && l < r) {
            l++;
            *oper += 6;
        }
        int temp = *(begin + l);
        *(begin + l) = *(begin + r);
        *(begin + r) = temp;
        *oper += 11;
    }
    *oper += 3;
    if (l > 0) {
        *oper += 1;
        quickSortHelper(begin, begin + l + 1, oper);
    }
    if (l < n - 1) {
        *oper += 1;
        quickSortHelper(begin + l + 1, end, oper);
    }
}

/// вызов быстрой сортировки
void quickSort(std::vector<int>& array, uint64_t *oper) {
    quickSortHelper(array.begin(), array.end(), oper);
}