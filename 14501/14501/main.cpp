//14501-���
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

	dfs(day + t[day], sum + p[day]);//����ϴ� ���
	dfs(day + 1, sum);//��� ���ϴ� ���
}

int main(){
	cin >> N;

	for (int i = 0; i<N; i++){
		cin >> t[i] >> p[i];
	}//�Է�

	dfs(0, 0);

	cout << result << '\n';
}