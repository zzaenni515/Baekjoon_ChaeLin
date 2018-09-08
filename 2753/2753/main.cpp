#include<iostream>
using namespace std;

int MIN_YEAR=1;
int MAX_YEAR = 4000;

int main(){
	int year;
	int result = 0;

	cin >> year;
	if (year < 1 || year>4000) return 0;	//입력 범위 넘었을 경우 프로그램 종료

	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))
		result = 1;//윤년
	cout << result;
	return 0;
}