#include <iostream>
#include <vector>
#include "InsertionSort.h"
using namespace std;

int compare_cnt_insertion = 0;
int datamove_cnt_insertion = 0;

void insertionSort(vector<itemType>& arr, int n) {
    int i, j;
    itemType v;

    compare_cnt_insertion = 0;
    datamove_cnt_insertion = 0;

    for (i = 1; i < n; i++) {
        v = arr[i]; 
        datamove_cnt_insertion++;

        j = i;
        while (++compare_cnt_insertion && j > 0 && arr[j - 1].totalScore < v.totalScore) {
            datamove_cnt_insertion++;
            arr[j] = arr[j - 1];
            j--;
        }
        
        arr[j] = v;
        datamove_cnt_insertion++;
        }
}

int insertionCompareCount() {
    return compare_cnt_insertion;
}

int insertionMoveCount() {
    return datamove_cnt_insertion;
}