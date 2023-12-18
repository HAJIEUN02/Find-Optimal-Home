#ifndef CALCULATEPOINT_H
#define CALCULATEPOINT_H

using namespace std;

#include <vector>
#include <limits>
#include "House.h"
using namespace std;

//최솟값과 최댓값을 저장하는 구조체
struct MinMax {
    float min;
    float max;
};

MinMax findMinMax(vector<House> houses, int House::* feature);

// 각 속성에 대한 최소값, 최대값, 가중치를 인자로 받아서 점수 계산
vector<House> calculateScores(vector<House> houses, int monthlyWeight, int depositWeight, int distanceWeight, int sizeWeight);

#endif //CSE_ALGORITHMPROJECT_CALCULATEPOINT_H