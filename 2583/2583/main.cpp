//2583-영역 구하기
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int k;
int arr[101][101];
int visit[101][101];
int cnt = 0;
int result = 1;
int zz[100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int x, int y) {
	visit[x][y] = 1;
	int sum = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == 0 && visit[nx][ny] == 0) {
			sum += dfs(nx, ny);
		}
	}
	return sum;
}

int main() {
	cin >> m >> n >> k;
	int z = 0;
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int a = y1; a < y2; a++) {
			for (int b = x1; b < x2; b++) {
				arr[a][b] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((arr[i][j] == 0) && (visit[i][j] == 0)) {
				zz[z++] = dfs(i, j);
			}
		}
	}
	sort(zz, zz + z);
	cout << z << '\n';
	for (int i = 0; i < z; i++) {
		cout << zz[i] << ' ';
	}
}