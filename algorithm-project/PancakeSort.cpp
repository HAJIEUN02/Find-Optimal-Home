#include "House.h"
#include <vector>
#include "PancakeSort.h"
#include <iostream>

int compare_cnt_pan = 0;
int datamove_cnt_pan = 0;

void flip(vector<House>& arr, int i) {
    int start = 0;
    while (start < i) {
        if (++datamove_cnt_pan && ++datamove_cnt_pan && ++datamove_cnt_pan && arr[start].totalScore < arr[i].totalScore) {
            swap(arr[start], arr[i]);
        }
        start++;
        i--;
    }
}

// 가장 큰 요소를 배열의 맨 끝으로 이동시키는 함수
int findMaxIndex(vector<House>& arr, int n) {
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (++compare_cnt_pan && arr[i].totalScore > arr[maxIdx].totalScore) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// 팬케이크 정렬 함수
vector<House> pancakeSort(vector<House>& arr) {
    int n = arr.size();

    compare_cnt_pan = 0;
    datamove_cnt_pan = 0;

    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);

        if (maxIndex != currSize - 1) {
            // 현재 크기의 가장 큰 요소를 맨 끝으로 이동
            flip(arr, maxIndex);

            // 현재 크기를 배열의 맨 끝으로 이동
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