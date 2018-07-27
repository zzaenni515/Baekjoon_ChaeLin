//14501-퇴사
#include<iostream>
using namespace std;

int N;
int t[16];
int p[16];
int result;

void dfs(int day, int sum){
	if (day>N) return;
	if (day == N){
		if (result<sum)
			result = sum;
		return;
	}

	dfs(day + t[day], sum + p[day]);//상담하는 경우
	dfs(day + 1, sum);//상담 안하는 경우
}

int main(){
	cin >> N;

	for (int i = 0; i<N; i++){
		cin >> t[i] >> p[i];
	}//입력

	dfs(0, 0);

	cout << result << '\n';
}