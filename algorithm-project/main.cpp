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
#include "InsertionSort.h"
#include <chrono>

using namespace std;

int main() {
	string line;
	ifstream file("houseInfo4000.txt"); //houseInfo ���� ����, ������ ����
	vector<House> houseList;
	// ����� ��
	int count;
	// �߿䵵
	int monthlyWeight;
	int depositWeight;
	int distanceWeight;
	int sizeWeight;
	cout << "--------------------------------------------------------------------------------------------\n";
	cout << "���Ͻô� ����� ����ŭ �Է� �� (����+������, ������, �Ÿ�, ���) 100���� �й��Ͽ� �߿䵵�� ǥ�����ּ���.\n";
	cout << "ex) ����� ��: 5, ����+������: 60, ������: 20, �Ÿ�:10, ���:10\n";
	cout << "--------------------------------------------------------------------------------------------\n";
	cout << "����� �� :";
	cin >> count;
	do {
		cout << "���� + ������ :";
		cin >> monthlyWeight;
		cout << "������ :";
		cin >> depositWeight;
		cout << "�Ÿ� :";
		cin >> distanceWeight;
		cout << "��� :";
		cin >> sizeWeight;

		if (monthlyWeight + depositWeight + distanceWeight + sizeWeight != 100) {
			cout << "����ġ�� ���� 100�� �ƴմϴ�. �ٽ� �Է����ּ���.\n";
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
				//���⿡ �о�� ������ ������ Ÿ���� �ٴ޶�.
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
		cout << "-----------------��õ ����� ������ ���--------------------\n";

		int data_num = 220; // ����ڰ� ������ ���� �ֺ��� �����ϴ� ������� ����
		auto insert_time = 0;
		auto quick_time = 0;

		if (data_num <= 200) { // �Ӱ谪 ������ ��� �ٷ� ���� ���� ����
			// Insertion �� ���� �ð� ���
			cout << "-----------------���� ����--------------------\n";
			auto insert_start_time = chrono::high_resolution_clock::now();
			insertionSort(houses, data_num-1);
			auto insert_end_time = chrono::high_resolution_clock::now();
			auto insert_duration = chrono::duration_cast<chrono::microseconds>(insert_end_time - insert_start_time);
			insert_time = insert_duration.count();
			cout << fixed;
			for (int p = 0; p < count; p++) {
				cout << p + 1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly << "��" << ", ������:" << houses[p].deposit << "��" << ", �Ÿ�: " << setprecision(0) << houses[p].distance << "m" << ", ��� : " << setprecision(2) << houses[p].size << "��" << endl;
				cout << "url : " << houses[p].url << endl;
			}
		}
		else {
			//quicksort �� ���� �ð� ���
			cout << "-----------------quicksort����--------------------\n";
			auto quick_start_time = chrono::high_resolution_clock::now();
			quicksort(houses, 0, data_num-1);
			auto quick_end_time = chrono::high_resolution_clock::now();
			auto quick_duration = chrono::duration_cast<chrono::microseconds>(quick_end_time - quick_start_time);
			quick_time = quick_duration.count();

			cout << fixed;
			for (int p = 0; p < count; p++) {
				cout << p + 1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly << "��" << ", ������:" << houses[p].deposit << "��" << ", �Ÿ�: " << setprecision(0) << houses[p].distance << "m" << ", ��� : " << setprecision(2) << houses[p].size << "��" << endl;
				cout << "url : " << houses[p].url << endl;
			}
		}

		// �񱳿��� �� �̵����� Ƚ�� ���
		cout << endl;
		cout << "-----QuickSort-----" << endl;
		cout << "�񱳿��� Ƚ��: " << quickCompareCount() << ", �̵����� Ƚ��: " << quickMoveCount() << endl;
		cout << "-----InsertionSort-----" << endl;
		cout << "�񱳿��� Ƚ��: " << insertionCompareCount() << ", �̵����� Ƚ��: " << insertionMoveCount() << endl;

		// ���� �ð� ���
		cout << endl;
		cout << "-----���� �� ���� ���� �ð� ���-----" << endl;
		cout << "QuickSort ���� �ð� : " << quick_time << "microseconds" << endl;
		cout << "InsertionSort ���� �ð� : " << insert_time << "microseconds" << endl;
	}
	else {
		cout << "������ ������ �ʾҾ��!";
	}
}