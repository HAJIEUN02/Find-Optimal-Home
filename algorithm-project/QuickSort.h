#include <vector>
#include "House.h"
using namespace std;
typedef House itemType;

#ifndef CSE_ALGORITHMPROJECT_QUICKSORT_H
#define CSE_ALGORITHMPROJECT_QUICKSORT_H

void swap(vector<itemType>& a, int i, int j);
int partition(vector<itemType>& a, int l, int r);
void quicksort(vector<itemType>& a, int l, int r);
int quickCompareCount();
int quickMoveCount();

#endif //CSE_ALGORITHMPROJECT_QUICKSORT_H
