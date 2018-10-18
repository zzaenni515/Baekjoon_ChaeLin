#include<iostream>
using namespace std;

int N;	//숫자 갯수
int Num[13];	//숫자 담을 배열
int ADD, SUB, MUL, NA;
int max_result=0, min_result=999999999;
int a = 0;
int check(int result){
	if (a == 1){
		min_result = max_result = result;
	}
	else{
		if (result < min_result) min_result = result;
		else if(result>max_result) max_result = result;
	}
	return 0;
}

int cal(int index, int add, int sub, int mul, int na, int mid_result){
	if ((add + sub + mul + na) == 0){	//더이상 연산할 연산자가 없을 경우
		a++;
		check(mid_result);
	}
	if (index >= N)	//더이상 계산할 숫자가 없는 경우 종료
		return 0;

	if (add != 0) cal(index+1, add - 1, sub, mul, na, mid_result+Num[index]);
	if (sub != 0) cal(index + 1, add, sub - 1, mul, na, mid_result - Num[index]);
	if (mul != 0) cal(index + 1, add, sub, mul - 1, na, mid_result*Num[index]);
	if (na != 0) cal(index + 1, add, sub, mul, na - 1, mid_result / Num[index]);
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> Num[i];
	}
	cin >> ADD >> SUB >> MUL >> NA;
	if ((ADD + SUB + MUL + NA) >= N){
		cout << "Error: 연산자 갯수 입력 오류 입니다" << endl;
	}

	if (ADD != 0) cal(2, ADD - 1, SUB, MUL, NA, Num[0] + Num[1]);
	if (SUB != 0) cal(2, ADD, SUB - 1, MUL, NA, Num[0] - Num[1]);
	if (MUL != 0) cal(2, ADD, SUB, MUL - 1, NA, Num[0] * Num[1]);
	if (NA != 0) cal(2, ADD, SUB, MUL, NA - 1, Num[0] / Num[1]);
	
	cout << max_result << endl << min_result << endl;
	return 0;
}