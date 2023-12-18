#include <iostream>
#include "House.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "CalculatePoint.h"
#include "PancakeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

using namespace std;

int main() {
    string line;
    ifstream file("houseInfo.txt"); //houseInfo 파일 열기, 없으면 생성
    vector<House> houseList;
    // 출력의 수
    int count;
    // 중요도
    int monthlyWeight;
    int depositWeight;
    int distanceWeight;
    int sizeWeight;
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "원하시는 출력의 수만큼 입력 후 (월세+관리비, 보증금, 거리, 평수) 100점을 분배하여 중요도를 표현해주세요.\n";
    cout << "ex) 출력의 수: 5, 월세+관리비: 60, 보증금: 20, 거리:10, 평수:10\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "출력의 수 :";
    cin >> count;
    do {
        cout << "월세 + 관리비 :";
        cin >> monthlyWeight;
        cout << "보증금 :";
        cin >> depositWeight;
        cout << "거리 :";
        cin >> distanceWeight;
        cout << "평수 :";
        cin >> sizeWeight;

        if (monthlyWeight + depositWeight + distanceWeight + sizeWeight != 100) {
            cout << "가중치의 합이 100이 아닙니다. 다시 입력해주세요.\n";
        }
    } while (monthlyWeight + depositWeight + distanceWeight + sizeWeight != 100);

    if (file.is_open()) {
        while (getline(file, line)) {

            vector<string> tempS;
            vector<double> tempD;
            istringstream ss(line);
            string field;
            int i = 0;
            int s = 0;
            int d = 0;
            string st = "";

            while (getline(ss, field, ',')) {
                //여기에 읽어온 값들의 데이터 타입이 다달라.
                if (i == 0 || i == 5) {
                    tempS.push_back(field);
                    s++;
                }
                else {
                    tempD.push_back(stod(field));
                    d++;
                }
                if (i >= 5) {
                    st += field;
                }
                i++;
            }
            House h;
            h.roadNameAddress = tempS.at(0);
            h.monthly = tempD.at(0);
            h.deposit = tempD.at(1);
            h.distance = tempD.at(2);
            h.size = tempD.at(3);
            h.url = st;

            houseList.push_back(h);


        }
        vector<House> houses = calculateScores(houseList, monthlyWeight, depositWeight, distanceWeight, sizeWeight);
        cout << "-----------------추천 자취방 순위별 출력--------------------\n";
        
        //quicksort정렬
        cout << "-----------------quicksort정렬--------------------\n";
        quicksort(houses, 0, 99);
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p + 1 << "순위) " << "주소: " << houses[p].roadNameAddress << ", 월세+관리비: " << setprecision(0) << houses[p].monthly << "원" << ", 보증금:" << houses[p].deposit << "원" << ", 거리: " << setprecision(0) << houses[p].distance << "m" << ", 평수 : " << setprecision(2) << houses[p].size << "평" << endl;
            cout << "url : " << houses[p].url << endl;
        }

        //shellSort정렬
        cout << "-----------------shellsort정렬--------------------\n";
        shellSort(houses,99); // houses는 참조로 전달됩니다.
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p+1 << "순위) " << "주소: " << houses[p].roadNameAddress << ", 월세+관리비: " << setprecision(0) << houses[p].monthly <<"원"<<", 보증금:"<< houses[p].deposit <<"원"<< ", 거리: " << setprecision(0) << houses[p].distance<<"m" << ", 평수 : " << setprecision(2) << houses[p].size <<"평"<< endl;
            cout << "url : " << houses[p].url << endl;
        }

        //pancake 정렬
        cout << "-----------------pancake정렬--------------------\n";
        vector<House> pancakeHouses = pancakeSort(houses);
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p+1 << "순위) " << "주소: " << pancakeHouses[p].roadNameAddress << ", 월세+관리비: " << setprecision(0) << pancakeHouses[p].monthly <<"원"<<", 보증금:"<< pancakeHouses[p].deposit <<"원"<< ", 거리: " << setprecision(0) << pancakeHouses[p].distance<<"m" << ", 평수 : " << setprecision(2) << pancakeHouses[p].size <<"평"<< endl;
            cout << "url : " << pancakeHouses[p].url << endl;
        }

        cout << "비교연산 횟수: " << shellCompareCount() << ", 이동연산 횟수: " << shellMoveCount() << endl;

    }
    else {
        cout << "파일이 열리지 않았어요!";
    }
}