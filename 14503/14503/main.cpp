//14503-로봇 청소기
#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int map[51][51];
int result = 0;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };//북,동,남,서

void dfs(int r, int c, int d) {
	//이동한 공간이 청소할수 있는지 확인(후진 했을때 벽일 경우 작동 멈춤)
	if (map[r][c] == 1) return;

	if (map[r][c] == 0) {//청소 안되어 있으면 청소하기.
		map[r][c] = 2;
		result++;
	}

	for (int i = 0; i < 4; i++) {
		int next_d = (d + 3) % 4;//북0->서3, 동1->북0, 남2->동1, 서3->남2
		int next_x = r + dx[next_d];
		int next_y = c + dy[next_d];//방향, 다음 위치 정해줌

		if (map[next_x][next_y] == 0) {//다음 위치가 청소 안되어 있으면 가서 청소(재귀)
			dfs(next_x, next_y, next_d);
			return;
		}
		else {//청소 할 공간이 아니면 변경된 방향만 가지고 있음.
			d = next_d;
		}
	}
	//위에서 4방향 다 탐색함.
	//이까지 내려온거면 네방향 중 더이상 청소할 공간이 없을 경우
	//후진 해야됨.
	if (d == 0)
		r++;
	else if (d == 1)
		c--;
	else if (d == 2)
		r--;
	else if (d == 3)
		c++;
	//후진 끝냈으니까 다시 재귀 
	dfs(r, c, d);
}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {//줄
		for (int j = 0; j < M; j++) {//열
			cin >> map[i][j];
		}
	}//map 입력

	dfs(r, c, d);

	cout << result << '\n';
}