#include <vector>

typedef std::vector<int>::iterator Iter;

/// слияние двух отсортированных частей массива
void merge(Iter begin, Iter middle, Iter end, uint64_t *oper) {
    std::vector<int> c(end - begin);
    Iter first_iter = begin;
    Iter second_iter = middle;
    Iter res_iter = c.begin();
    *oper += 4;
    for (; first_iter != middle && second_iter != end; ++res_iter) {
        if (*first_iter < *second_iter) {
            *res_iter = *first_iter;
            ++first_iter;
        } else {
            *res_iter = *second_iter;
            ++second_iter;
        }
        *oper += 11;
    }
    while (first_iter != middle) {
        *res_iter = *first_iter;
        ++first_iter;
        ++res_iter;
        *oper += 5;
    }
    while (second_iter != end) {
        *res_iter = *second_iter;
        ++second_iter;
        ++res_iter;
        *oper += 5;
    }
    first_iter = begin;
    res_iter = c.begin();
    *oper += 2;
    for (; res_iter != c.end(); ++res_iter, ++first_iter) {
        *first_iter = *res_iter;
        *oper += 6;
    }
}

/// сортировка слиянием
void mergeSortHelper(Iter begin, Iter end, uint64_t *oper) {
    *oper += 2;
    if (begin + 1 == end) {
        return;
    }
    *oper += 2;
    Iter middle = begin + (end - begin) / 2;
    mergeSortHelper(begin, middle, oper);
    mergeSortHelper(middle, end, oper);
    merge(begin, middle, end, oper);
}

/// вызов сортировки слиянием
void mergeSort(std::vector<int>& array, uint64_t *oper) {
    mergeSortHelper(array.begin(), array.end(), oper);
}