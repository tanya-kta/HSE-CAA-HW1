#include <vector>

/// сортировка подсчетом
void countingSort(std::vector<int>& array, uint64_t *oper) {
    int n = array.size();
    *oper += 2;
    std::vector<int> cnt(4101), ans(n);
    for (int i = 0; i < n; ++i) {
        ++cnt[array[i]];
        *oper += 5;
    }
    *oper++;
    for (int i = 1; i <= 4100; ++i) {
        cnt[i] += cnt[i - 1];
        *oper += 6;
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[array[i]]--;
        ans[cnt[array[i]]] = array[i];
        *oper += 10;
    }
    for (int i = 0; i < n; ++i) {
        array[i] = ans[i];
        *oper += 5;
    }
}
