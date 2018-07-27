//13460-구슬 탈출2
#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int hx, hy;
	int rx, ry;
	int bx, by;
	int rh = 0;
	int bh = 0;
	int cnt = 0;
};

int N, M;
char map[11][11];

queue<pos> q;

int main() {
	pos p;
	ios_base::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {//구멍
				p.hx = i;
				p.hy = j;
			}
			else if (map[i][j] == 'R') {
				p.rx = i;
				p.ry = j;
			}
			else if (map[i][j] == 'B') {
				p.bx = i;
				p.by = j;
			}
		}
	}//입력끝

	//bfs
	q.push(p);

	while (!q.empty()) {
		if (q.front().cnt >= 10) {// 움직인 횟수가 10번 이상이면 -1 출력
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			///////////////////동쪽으로 이동
			if (dir == 0) {
				pos temp = q.front();//새로운 큐에 현재 위치 다 넣기.
				int conby = temp.by;
				int conry = temp.ry;
				//벽이나올때까지 이동(빨강, 파랑)
				while (map[temp.rx][conry + 1] != '#') {//빨간공
					if (map[temp.rx][conry + 1] == 'O') {
						temp.rh = 1;//빨간공 구멍에 들어감.
						break;
					}
					conry++;//구멍에 안들어갔으면 벽에 도착할때까지 움직임.
				}

				while (map[temp.bx][conby + 1] != '#') {
					if (map[temp.bx][conby + 1] == 'O') {
						temp.bh = 1;//파란공 구멍에 들어감
						break;
					}
					conby++;
				}
				//////빨강 파란공이 겹쳤으면 위치 확인해서 조정하기
				if (temp.rx == temp.bx&& conry == conby) {
					if (temp.by > temp.ry) {//동쪽으로 움직이기전 파란공이 더 오른쪽에 있었다면 빨간공 가로 위치--
						conry--;
					}
					else {
						conby--;
					}
				}
				////////빨간공만 구멍에 들어갔으면 cnt 출력
				if (temp.bh == 0 && temp.rh == 1) {
					cout << temp.cnt + 1 << '\n';
					return 0;
				}
				//둘다 구멍에 들어가면 -1 출력

				//////////둘다 구멍에 안들어갔으면 cnt++, 현재 위치 push()하기
				if (temp.bh == 0 && temp.rh == 0) {
					temp.cnt++;
					temp.by = conby;
					temp.ry = conry;
					q.push(temp);
				}
			}
			///////////////////서쪽으로 이동
			else if (dir == 1) {
				pos temp = q.front();
				int conby = temp.by;
				int conry = temp.ry;

				while (map[temp.rx][conry - 1] != '#') {
					if (map[temp.rx][conry - 1] == 'O') {
						temp.rh = 1;
						break;
					}
					conry--;
				}//빨간공이동

				while (map[temp.bx][conby - 1] != '#') {
					if (map[temp.bx][conby - 1] == 'O') {
						temp.bh = 1;
						break;
					}
					conby--;
				}//파란공이동

				if (temp.rx == temp.bx&&conry == conby) {
					if (temp.ry < temp.by) {
						conby++;
					}
					else {
						conry++;
					}
				}//겹쳤을때 좌표 조정

				if (temp.bh == 0 && temp.rh == 1) {
					cout << temp.cnt + 1 << '\n';
					return 0;
				}//빨간공만 구멍에 들어갔을 때 cnt출력

				if (temp.bh == 0 && temp.rh == 0) {
					temp.cnt++;
					temp.ry = conry;
					temp.by = conby;
					q.push(temp);
				}
			}
			///////////////////남쪽으로 이동
			else if (dir == 2) {
				pos temp = q.front();
				int conrx = temp.rx;
				int conbx = temp.bx;

				while (map[conrx + 1][temp.ry] != '#') {
					if (map[conrx + 1][temp.ry] == 'O') {
						temp.rh = 1;
						break;
					}
					conrx++;
				}

				while (map[conbx + 1][temp.by] != '#') {
					if (map[conbx + 1][temp.by] == 'O') {
						temp.bh = 1;
						break;
					}
					conbx++;
				}

				if (temp.by == temp.ry&& conrx == conbx) {
					if (temp.rx < temp.bx) {
						conrx--;
					}
					else {
						conbx--;
					}
				}

				if (temp.bh == 0 && temp.rh == 1) {
					cout << temp.cnt + 1 << '\n';
					return 0;
				}

				if (temp.bh == 0 && temp.rh == 0) {
					temp.cnt++;
					temp.rx = conrx;
					temp.bx = conbx;
					q.push(temp);
				}

			}
			///////////////////북쪽으로 이동
			else {
				pos temp = q.front();
				int conrx = temp.rx;
				int conbx = temp.bx;

				while (map[conrx - 1][temp.ry] != '#') {
					if (map[conrx - 1][temp.ry] == 'O') {
						temp.rh = 1;
						break;
					}
					conrx--;
				}

				while (map[conbx - 1][temp.by] != '#') {
					if (map[conbx - 1][temp.by] == 'O') {
						temp.bh = 1;
						break;
					}
					conbx--;
				}

				if (temp.by == temp.ry&&conrx == conbx) {
					if (temp.rx < temp.bx) {
						conbx++;
					}
					else {
						conrx++;
					}
				}

				if (temp.bh == 0 && temp.rh == 1) {
					cout << temp.cnt + 1 << '\n';
					return 0;
				}

				if (temp.bh == 0 && temp.rh == 0) {
					temp.cnt++;
					temp.rx = conrx;
					temp.bx = conbx;
					q.push(temp);
				}
			}
		}
		q.pop();
	}
	cout << "-1";
	return 0;
}