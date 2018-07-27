//14888-������ �����ֱ�
#include<iostream>
using namespace std;

int N;	//�Է��� ������ ����
int A[12];	//���� ���� �迭
int add, sub, mul, na;	//������ ����
int cnt;	//������ ī����
//int result;
int Max = -10e9;
int Min = 10e9;

void dfs(int arr[12], int add1, int sub1, int mul1, int div, int result, int cnt) {
	if (cnt == N) {//���� �� ���� �� max, min�� ���ϱ�
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
