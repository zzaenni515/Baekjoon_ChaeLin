//14889-��ŸƮ�� ��ũ
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
			start_power += S[start[i]][start[j]] + S[start[j]][start[i]];//start���� �ɷ�ġ���
			link_power += S[link[i]][link[j]] + S[link[j]][link[i]];//link���� �ɷ�ġ ���.
		}
	}//��� ��

	result = min(result, abs(start_power - link_power));
}

void dfs(int index, vector<int> &start, vector<int> &link) {
	if (start.size() > N / 2) return;
	if (link.size() > N / 2) return;
	if (index == N) {
		if (start.size() == N / 2 && link.size() == N / 2) {//�� �� �������
			cal(start, link);
		}
		return;
	}

	start.push_back(index);//index��° ��� start���� �ֱ�
	dfs(index + 1, start, link);
	start.pop_back();//������

	link.push_back(index);//index��° ��� link���� �ֱ�
	dfs(index + 1, start, link);
	link.pop_back();//������
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}//�Է�

	vector<int> start, right;
	dfs(0, start, right);

	cout << result << '\n';
}