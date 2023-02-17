#include <vector>

typedef std::vector<int>::iterator Iter;

/// слияние двух отсортированных частей массива
void merge(Iter begin, Iter middle, Iter end) {
    std::vector<int> c(end - begin);
    Iter first_iter = begin;
    Iter second_iter = middle;
    Iter res_iter = c.begin();
    for (; first_iter != middle && second_iter != end; ++res_iter) {
        if (*first_iter < *second_iter) {
            *res_iter = *first_iter;
            ++first_iter;
        } else {
            *res_iter = *second_iter;
            ++second_iter;
        }
    }
    while (first_iter != middle) {
        *res_iter = *first_iter;
        ++first_iter;
        ++res_iter;
    }
    while (second_iter != end) {
        *res_iter = *second_iter;
        ++second_iter;
        ++res_iter;
    }
    first_iter = begin;
    res_iter = c.begin();
    for (; res_iter != c.end(); ++res_iter, ++first_iter) {
        *first_iter = *res_iter;
    }
}

/// сортировка слиянием
void mergeSortHelper(Iter begin, Iter end) {
    if (begin + 1 == end) {
        return;
    }

    Iter middle = begin + (end - begin) / 2;
    mergeSortHelper(begin, middle);
    mergeSortHelper(middle, end);
    merge(begin, middle, end);
}

/// вызов сортировки слиянием
void mergeSort(std::vector<int>& array) {
    mergeSortHelper(array.begin(), array.end());
}