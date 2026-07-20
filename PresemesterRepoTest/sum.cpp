#include "sum.h"

int sum(const std::vector<int> &vec) {
    int total = 0;
    for (int num : vec) {
        total += num;
    }
    return total;   
}