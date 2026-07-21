#include "vectorsum.h"

int vectorSum(const std::vector<int> &vec) {
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    return sum;
}
