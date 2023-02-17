#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<int> smallRangeArray(int size) {
    std::srand(std::time(nullptr));
    std::vector<int> array(size);
    for(int i = 0; i < size; ++i) {
        array[i] = std::rand() % 6;
    }
    return array;
}

std::vector<int> largeRangeArray(int size) {
    std::srand(std::time(nullptr));
    std::vector<int> array(size);
    for(int i = 0; i < size; ++i) {
        array[i] = std::rand() % 4001;
    }
    return array;
}

std::vector<int> decreasingArray(int size) {
    std::vector<int> array(size);
    for(int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
    return array;
}

std::vector<int> almostSortedArray(int size) {
    std::vector<int> array(size);
    for(int i = 0; i < size; ++i) {
        array[i] = i + 1;
        if (i > 0 && i % 100 == 0) {
            std::swap(array[i - 10], array[i - 90]);
            std::swap(array[i - 20], array[i - 80]);
        }
    }
    return array;
}
