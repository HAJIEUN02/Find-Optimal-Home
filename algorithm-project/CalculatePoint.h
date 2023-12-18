#ifndef CALCULATEPOINT_H
#define CALCULATEPOINT_H

using namespace std;

#include <vector>
#include <limits>
#include "House.h"
using namespace std;

//�ּڰ��� �ִ��� �����ϴ� ����ü
struct MinMax {
    float min;
    float max;
};

MinMax findMinMax(vector<House> houses, int House::* feature);

// �� �Ӽ��� ���� �ּҰ�, �ִ밪, ����ġ�� ���ڷ� �޾Ƽ� ���� ���
vector<House> calculateScores(vector<House> houses, int monthlyWeight, int depositWeight, int distanceWeight, int sizeWeight);

#endif //CSE_ALGORITHMPROJECT_CALCULATEPOINT_H