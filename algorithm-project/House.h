#ifndef HOUSE_H
#define HOUSE_H
#include <string>

using namespace std;

struct House {
    string roadNameAddress; //���θ� �ּ�
    float monthly;     // ���� + ������
    float deposit;      // ������
    float distance;    // �Ű��а����κ��� �Ÿ�
    float size;         // ���
    string url;
    float totalScore;
};
#endif