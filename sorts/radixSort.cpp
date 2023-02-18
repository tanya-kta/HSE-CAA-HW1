#include <vector>

/// цифровая сортировка по основанию 256
void radixSort(std::vector<int>& array) {
    int n = array.size();
    for (int k = 0; k < 4; ++k) {
        std::vector<int> values(256);
        int mask = (1 << 8) - 1;
        for (int i = 0; i < n; ++i) {
            int byte = (array[i] >> (k * 8)) & mask;
            ++values[byte];
        }
        for (int i = 1; i < 256; ++i) {
            values[i] += values[i - 1];
        }
        std::vector<int> sorted(n);
        for (int i = n - 1; i >= 0; --i) {
            int byte = (array[i] >> (k * 8)) & mask;
            values[byte]--;
            sorted[values[byte]] = array[i];
        }
        for (int i = 0; i < n; ++i) {
            array[i] = sorted[i];
        }
    }
}
