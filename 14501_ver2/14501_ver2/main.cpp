#include<iostream>
using namespace std;

int N;	//백준이 상담 가능한 일 수
int T[17], P[17];	//각 상담별 기간, 비용 기록할 배열
int max_pay;	//백준이의 최대 이익

int check(int index, int pay){
	if (index > N) return 0;	//퇴사일을 넘기면 종료
	if (index == N){	//N명까지 비교헀을 경우
		if (pay > max_pay) 
			max_pay = pay;
		return 0;
	}

	check(index + T[index], pay + P[index]);	//index번째 사람 상담 할 경우
	check(index + 1, pay);	//index번째 사람 상담 안할 경우

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