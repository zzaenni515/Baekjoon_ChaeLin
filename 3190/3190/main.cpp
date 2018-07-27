//3190-뱀
#include <iostream>
#include<list>
using namespace std;

int map[100][100] = { 0 };
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };//(0:위,1:오른쪽,2:아래,3:왼쪽)
int n;//맵 크기(2~100)
int k;//사과 갯수(0~100)
int kr, kc;//사과의 행,열
int l;//뱀의 방향변환 갯수(1~100)
int x;//몇초후에 방향전환할건지 초 수.
char c;//L(왼)또는D(오)
typedef pair<int, int> IIpair;
typedef pair<int, char> ICpair;

int main() {
	cin >> n;//맵크기
	cin >> k;//사과갯수

	for (int i = 0; i < k; i++) {
		cin >> kr >> kc;
		map[kr - 1][kc - 1] = 2;
	}//사과있는자리는 2로 표시.

	cin >> l;//뱀의 방향변환 갯수 입력.
	ICpair moving[100];

	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		moving[i] = make_pair(x, c);//움직임 저장.
	}

	list<IIpair> snake;
	snake.push_front(make_pair(0, 0));
	map[0][0] = 1;//뱀위치 초기화.

	int dir = 1, hc = 0, hr = 0, move = 0;
	int t = 1;
	while (1) {
		int nr = hr + dr[dir];
		int nc = hc + dc[dir];

		if (nc < 0 || nc >= n || nr < 0 || nr >= n || map[nr][nc] == 1)
			break;
		if (map[nr][nc] == 0) {//사과없으면 꼬리없앰.
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		map[nr][nc] = 1;//다음칸에 머리 늘리는 의미.
		snake.push_front(make_pair(nr, nc));
		hr = nr;
		hc = nc;//머리의 행, 열 갱신.

		if (move < l&&moving[move].first == t) {
			dir = (dir + (moving[move++].second == 'L' ? 3 : 1)) % 4;
		}
		t++;
	}
	printf("%d\n", t);
}