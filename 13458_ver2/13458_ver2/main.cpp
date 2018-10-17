#include<iostream>
using namespace std;

int N, B, C;	//시험장수, 총감독 커버가능 인원수, 부감독 커버가능 인원수
int room[10000002];	//각 시험장당 응시인원 수


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
		}	//총감독관 한명만 감독해도 가능한 경우
		else{	//부감독관 필요한 경우
			int students = room[i] - B;
			count = count + (students / C) + 1;
			if (students%C != 0) count++;
		}
	}

	cout << count << endl;

	return 0;
}