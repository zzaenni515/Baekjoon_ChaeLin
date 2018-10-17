#include<iostream>
using namespace std;

int N, B, C;	//�������, �Ѱ��� Ŀ������ �ο���, �ΰ��� Ŀ������ �ο���
int room[10000002];	//�� ������� �����ο� ��


int main(){
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> room[i];
	}
	cin >> B >> C;

	long long count = 0;
	for (int i = 0; i < N; i++){
		if (room[i] <= B){
			count++;
		}	//�Ѱ����� �Ѹ� �����ص� ������ ���
		else{	//�ΰ����� �ʿ��� ���
			int students = room[i] - B;
			count = count + (students / C) + 1;
			if (students%C != 0) count++;
		}
	}

	cout << count << endl;

	return 0;
}