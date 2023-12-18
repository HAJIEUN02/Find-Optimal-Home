#include "QuickSort.h"

int compare_Cnt = 0;
int dataMove_Cnt = 0;

void swap(vector<itemType>& a, int i, int j) {
    itemType t = a[i];
    dataMove_Cnt++;
    a[i] = a[j];
    dataMove_Cnt++;
    a[j] = t;
    dataMove_Cnt++;
}

int partition(vector<itemType>& a, int l, int r) {
    int i, j; double v;
    if (r > l) {
        v = a.at(l).totalScore;
        i = l;
        j = r + 1;
        // 항상 돌아간다는 뜻
        for (;;) {
            while (++compare_Cnt && a[++i].totalScore > v);
            while (++compare_Cnt && a[--j].totalScore < v);
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, j, l);
    }
    return j;
}

void quicksort(vector<itemType>& a, int l, int r) {
    int  j;
    if (r > l) {
        j = partition(a, l, r);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

int quickCompareCount() {
    return compare_Cnt;
}

int quickMoveCount() {
    return dataMove_Cnt;
}