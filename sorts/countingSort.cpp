#include <vector>

/// сортировка подсчетом
void countingSort(std::vector<int>& array) {
    int n = array.size();
    std::vector<int> cnt(4101), ans(n);
    for (int i = 0; i < n; ++i) {
        ++cnt[array[i]];
    }
    for (int i = 1; i <= 4100; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[array[i]]--;
        ans[cnt[array[i]]] = array[i];
    }
    for (int i = 0; i < n; ++i) {
        array[i] = ans[i];
    }
}
