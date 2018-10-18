#include<iostream>
using namespace std;

int N;	//������ ��� ������ �� ��
int T[17], P[17];	//�� ��㺰 �Ⱓ, ��� ����� �迭
int max_pay;	//�������� �ִ� ����

int check(int index, int pay){
	if (index > N) return 0;	//������� �ѱ�� ����
	if (index == N){	//N����� ������ ���
		if (pay > max_pay) 
			max_pay = pay;
		return 0;
	}

	check(index + T[index], pay + P[index]);	//index��° ��� ��� �� ���
	check(index + 1, pay);	//index��° ��� ��� ���� ���

	return 0;
}

int main(){
	cin >> N;
	max_pay = 0;
	for (int i = 0; i < N; i++){
		cin >> T[i] >> P[i];
	}

	check(0, 0);
	
	cout << max_pay << endl;
	return 0;
}