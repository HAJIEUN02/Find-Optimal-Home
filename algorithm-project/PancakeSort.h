#include <vector>

#ifndef CSE_ALGORITHMPROJECT_PANCAKESORT_H
#define CSE_ALGORITHMPROJECT_PANCAKESORT_H

extern int compare_cnt_pan;
extern int datamove_cnt_pan;

void flip(vector<House>& arr, int i);
int findMaxIndex(vector<House>& arr, int n);
vector<House> pancakeSort(vector<House>& arr);
int pancakeCompareCount();
int pancakeMoveCount();

#endif //CSE_ALGORITHMPROJECT_PANCAKESORT_H