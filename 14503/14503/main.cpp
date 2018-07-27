//14503-�κ� û�ұ�
#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int map[51][51];
int result = 0;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };//��,��,��,��

void dfs(int r, int c, int d) {
	//�̵��� ������ û���Ҽ� �ִ��� Ȯ��(���� ������ ���� ��� �۵� ����)
	if (map[r][c] == 1) return;

	if (map[r][c] == 0) {//û�� �ȵǾ� ������ û���ϱ�.
		map[r][c] = 2;
		result++;
	}

	for (int i = 0; i < 4; i++) {
		int next_d = (d + 3) % 4;//��0->��3, ��1->��0, ��2->��1, ��3->��2
		int next_x = r + dx[next_d];
		int next_y = c + dy[next_d];//����, ���� ��ġ ������

		if (map[next_x][next_y] == 0) {//���� ��ġ�� û�� �ȵǾ� ������ ���� û��(���)
			dfs(next_x, next_y, next_d);
			return;
		}
		else {//û�� �� ������ �ƴϸ� ����� ���⸸ ������ ����.
			d = next_d;
		}
	}
	//������ 4���� �� Ž����.
	//�̱��� �����°Ÿ� �׹��� �� ���̻� û���� ������ ���� ���
	//���� �ؾߵ�.
	if (d == 0)
		r++;
	else if (d == 1)
		c--;
	else if (d == 2)
		r--;
	else if (d == 3)
		c++;
	//���� �������ϱ� �ٽ� ��� 
	dfs(r, c, d);
}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {//��
		for (int j = 0; j < M; j++) {//��
			cin >> map[i][j];
		}
	}//map �Է�

	dfs(r, c, d);

	cout << result << '\n';
}