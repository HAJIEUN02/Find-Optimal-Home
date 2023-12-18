#include <vector>
#include "House.h"
typedef House itemType;

extern int compare_cnt_insertion;
extern int datamove_cnt_insertion;

void insertionSort(vector<itemType>& arr, int n);
int insertionCompareCount();
int insertionMoveCount();