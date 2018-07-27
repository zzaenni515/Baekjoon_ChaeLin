//14888-연산자 끼워넣기
#include<iostream>
using namespace std;

int N;	//입력할 숫자의 갯수
int A[12];	//숫자 넣을 배열
int add, sub, mul, na;	//연산자 갯수
int cnt;	//연산자 카운팅
//int result;
int Max = -10e9;
int Min = 10e9;

void dfs(int arr[12], int add1, int sub1, int mul1, int div, int result, int cnt) {
	if (cnt == N) {//연산 다 했을 때 max, min값 구하기
		if (result > Max)
			Max = result;
		if (result < Min)
			Min = result;
	}

	if (add1 > 0) {
		dfs(arr, add1 - 1, sub1, mul1, div, result + arr[cnt], cnt + 1);
	}
	if (sub1 > 0) {
		dfs(arr, add1, sub1 - 1, mul1, div, result - arr[cnt], cnt + 1);
	}
	if (mul1 > 0) {
		dfs(arr, add1, sub1, mul1 - 1, div, result * arr[cnt], cnt + 1);
	}
	if (div > 0) {
		dfs(arr, add1, sub1, mul1, div - 1, result / arr[cnt], cnt + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> add >> sub >> mul >> na;
	cnt = 1;
	dfs(A, add, sub, mul, na, A[0], cnt);

	cout << Max << '\n' << Min;
}
