#include<iostream>
using namespace std;

int MIN_YEAR=1;
int MAX_YEAR = 4000;

int main(){
	int year;
	int result = 0;

	cin >> year;
	if (year < 1 || year>4000) return 0;	//�Է� ���� �Ѿ��� ��� ���α׷� ����

	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))
		result = 1;//����
	cout << result;
	return 0;
}