//14889-스타트와 링크
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N;
int S[21][21];
int result = 100000000;

void cal(vector<int> &start, vector<int> &link) {
	int start_power = 0;
	int link_power = 0;

	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			start_power += S[start[i]][start[j]] + S[start[j]][start[i]];//start팀의 능력치계산
			link_power += S[link[i]][link[j]] + S[link[j]][link[i]];//link팀의 능력치 계산.
		}
	}//계산 끝

	result = min(result, abs(start_power - link_power));
}

void dfs(int index, vector<int> &start, vector<int> &link) {
	if (start.size() > N / 2) return;
	if (link.size() > N / 2) return;
	if (index == N) {
		if (start.size() == N / 2 && link.size() == N / 2) {//팀 다 나눈경우
			cal(start, link);
		}
		return;
	}

	start.push_back(index);//index번째 사람 start팀에 넣기
	dfs(index + 1, start, link);
	start.pop_back();//꺼내기

	link.push_back(index);//index번째 사람 link팀에 넣기
	dfs(index + 1, start, link);
	link.pop_back();//꺼내기
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}//입력

	vector<int> start, right;
	dfs(0, start, right);

	cout << result << '\n';
}