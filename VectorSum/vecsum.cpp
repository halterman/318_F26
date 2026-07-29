#include "vectorsum.h"

int vector_sum(const std::vector<int> &vec) {
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    return sum;
}
