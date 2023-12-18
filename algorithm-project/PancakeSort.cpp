#include "House.h"
#include <vector>
#include "PancakeSort.h"
int compare_cnt_pan = 0;
int datamove_cnt_pan = 0;

void flip(vector<House>& arr, int i) {
    int start = 0;
    while (start < i) {
        if (arr[start].totalScore < arr[i].totalScore) {
            swap(arr[start], arr[i]);
            datamove_cnt_pan = datamove_cnt_pan + 3;
        }
        start++;
        i--;
    }
}

// ���� ū ��Ҹ� �迭�� �� ������ �̵���Ű�� �Լ�
int findMaxIndex(vector<House>& arr, int n) {
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].totalScore > arr[maxIdx].totalScore && compare_cnt_pan++) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// ������ũ ���� �Լ�
vector<House> pancakeSort(vector<House>& arr) {
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);

        if (maxIndex != currSize - 1) {
            // ���� ũ���� ���� ū ��Ҹ� �� ������ �̵�
            flip(arr, maxIndex);

            // ���� ũ�⸦ �迭�� �� ������ �̵�
            flip(arr, currSize - 1);
        }
    }
    return arr;
}

int pancakeCompareCount() {
    return compare_cnt_pan;
}

int pancakeMoveCount() {
    return datamove_cnt_pan;
}