//14502-연구소
#include <iostream>
#include <queue>
using namespace std;

struct POS {
	int y, x;
};//바이러스 위치

int N, M;
int num0 = 0, num2 = 0;
int result = 0;
POS pos[11];//바이러스 좌표 담을 공간.

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };//븍, 서, 남, 동


void bfs(int arr[10][10]) {
	int tmp0 = num0;
	int tmpArr[10][10];

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			tmpArr[i][j] = arr[i][j];//맵 복사
		}
	}

	for (int i = 0; i < num2; i++) {
		queue<POS> q;
		q.push(pos[i]);

		while (!q.empty()) {
			POS tmp;
			tmp = q.front();
			q.pop();

			for (int j = 0; j< 4; j++) {//4방향 모두 확인
				int ny = tmp.y + dy[j];
				int nx = tmp.x + dx[j];

				if (tmpArr[ny][nx] == 0) {
					tmp0--;//영역 감소 시키기.
					tmpArr[ny][nx] = 2;//바이러스 감염
					q.push({ ny, nx });
				}
			}
		}
	}//초기 바이러스 모든 좌표에서 알아봄.

	if (tmp0 > result)
		result = tmp0;
}

void dfs(int arr[10][10], int y, int x, int cnt) {

	if (cnt == 3) {//벽 세개 세웠으면 넓이구하러 bfs호출
		bfs(arr);
		return;
	}

	for (int j = x; j <= M; j++) {//가로로 벽 세우기
		if (arr[y][j] == 0) {
			arr[y][j] = 1;//벽세우기
			dfs(arr, y, j, cnt + 1);//재귀
			arr[y][j] = 0;//원상복구 시킴.
		}
	}

	for (int i = y + 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;//벽세우기
				dfs(arr, i, j, cnt + 1);
				arr[i][j] = 0;//원상복구 시키기
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
				map[i][j] = -1;//테두리 표시하기(사용X)
				continue;
			}
			cin >> map[i][j];
			if (map[i][j] == 2) {
				//바이러스 위치 담기, 바이러스 갯수 ++
				pos[num2].y = i;
				pos[num2].x = j;
				num2++;
			}
			else if (map[i][j] == 0)
				num0++;
		}
	}
	num0 -= 3;//벽 3개 세우니까  최대안전지역 넓이.
	dfs(map, 1, 1, 0);

	cout << result << '\n';
}