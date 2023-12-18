#ifndef HOUSE_H
#define HOUSE_H
#include <string>

using namespace std;

struct House {
    string roadNameAddress; //도로명 주소
    float monthly;     // 월세 + 관리비
    float deposit;      // 보증금
    float distance;    // 신공학관으로부터 거리
    float size;         // 평수
    string url;
    float totalScore;
};
#endif