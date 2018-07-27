//14502-������
#include <iostream>
#include <queue>
using namespace std;

struct POS {
	int y, x;
};//���̷��� ��ġ

int N, M;
int num0 = 0, num2 = 0;
int result = 0;
POS pos[11];//���̷��� ��ǥ ���� ����.

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };//��, ��, ��, ��


void bfs(int arr[10][10]) {
	int tmp0 = num0;
	int tmpArr[10][10];

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			tmpArr[i][j] = arr[i][j];//�� ����
		}
	}

	for (int i = 0; i < num2; i++) {
		queue<POS> q;
		q.push(pos[i]);

		while (!q.empty()) {
			POS tmp;
			tmp = q.front();
			q.pop();

			for (int j = 0; j< 4; j++) {//4���� ��� Ȯ��
				int ny = tmp.y + dy[j];
				int nx = tmp.x + dx[j];

				if (tmpArr[ny][nx] == 0) {
					tmp0--;//���� ���� ��Ű��.
					tmpArr[ny][nx] = 2;//���̷��� ����
					q.push({ ny, nx });
				}
			}
		}
	}//�ʱ� ���̷��� ��� ��ǥ���� �˾ƺ�.

	if (tmp0 > result)
		result = tmp0;
}

void dfs(int arr[10][10], int y, int x, int cnt) {

	if (cnt == 3) {//�� ���� �������� ���̱��Ϸ� bfsȣ��
		bfs(arr);
		return;
	}

	for (int j = x; j <= M; j++) {//���η� �� �����
		if (arr[y][j] == 0) {
			arr[y][j] = 1;//�������
			dfs(arr, y, j, cnt + 1);//���
			arr[y][j] = 0;//���󺹱� ��Ŵ.
		}
	}

	for (int i = y + 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;//�������
				dfs(arr, i, j, cnt + 1);
				arr[i][j] = 0;//���󺹱� ��Ű��
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int map[10][10];

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				map[i][j] = -1;//�׵θ� ǥ���ϱ�(���X)
				continue;
			}
			cin >> map[i][j];
			if (map[i][j] == 2) {
				//���̷��� ��ġ ���, ���̷��� ���� ++
				pos[num2].y = i;
				pos[num2].x = j;
				num2++;
			}
			else if (map[i][j] == 0)
				num0++;
		}
	}
	num0 -= 3;//�� 3�� ����ϱ�  �ִ�������� ����.
	dfs(map, 1, 1, 0);

	cout << result << '\n';
}