#include "ShellSort.h"

int compare_cnt_shell = 0;
int datamove_cnt_shell = 0;

void shellSort(vector<House>& a, int n) {
    int h = 1;
    do {
        h = 3 * h + 1;
    } while (h < n);

    do {
        h = h / 3;
        for (int i = h; i < n; i++) {
            House v = a[i];

            int j = i;
            while (++compare_cnt_shell && j >= h && a[j - h].totalScore < v.totalScore) {
                a[j] = a[j - h]; 
                datamove_cnt_shell++;
                j -= h;
            }
            a[j] = v;
            datamove_cnt_shell++;
        }
    } while (h > 1);
}

int shellCompareCount() {
    return compare_cnt_shell;
}

int shellMoveCount() {
    return datamove_cnt_shell;
}