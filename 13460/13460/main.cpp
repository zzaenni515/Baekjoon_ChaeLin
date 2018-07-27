//13460-���� Ż��2
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
			if (map[i][j] == 'O') {//����
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
	}//�Է³�

	//bfs
	q.push(p);

	while (!q.empty()) {
		if (q.front().cnt >= 10) {// ������ Ƚ���� 10�� �̻��̸� -1 ���
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			///////////////////�������� �̵�
			if (dir == 0) {
				pos temp = q.front();//���ο� ť�� ���� ��ġ �� �ֱ�.
				int conby = temp.by;
				int conry = temp.ry;
				//���̳��ö����� �̵�(����, �Ķ�)
				while (map[temp.rx][conry + 1] != '#') {//������
					if (map[temp.rx][conry + 1] == 'O') {
						temp.rh = 1;//������ ���ۿ� ��.
						break;
					}
					conry++;//���ۿ� �ȵ����� ���� �����Ҷ����� ������.
				}

				while (map[temp.bx][conby + 1] != '#') {
					if (map[temp.bx][conby + 1] == 'O') {
						temp.bh = 1;//�Ķ��� ���ۿ� ��
						break;
					}
					conby++;
				}
				//////���� �Ķ����� �������� ��ġ Ȯ���ؼ� �����ϱ�
				if (temp.rx == temp.bx&& conry == conby) {
					if (temp.by > temp.ry) {//�������� �����̱��� �Ķ����� �� �����ʿ� �־��ٸ� ������ ���� ��ġ--
						conry--;
					}
					else {
						conby--;
					}
				}
				////////�������� ���ۿ� ������ cnt ���
				if (temp.bh == 0 && temp.rh == 1) {
					cout << temp.cnt + 1 << '\n';
					return 0;
				}
				//�Ѵ� ���ۿ� ���� -1 ���

				//////////�Ѵ� ���ۿ� �ȵ����� cnt++, ���� ��ġ push()�ϱ�
				if (temp.bh == 0 && temp.rh == 0) {
					temp.cnt++;
					temp.by = conby;
					temp.ry = conry;
					q.push(temp);
				}
			}
			///////////////////�������� �̵�
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
				}//�������̵�

				while (map[temp.bx][conby - 1] != '#') {
					if (map[temp.bx][conby - 1] == 'O') {
						temp.bh = 1;
						break;
					}
					conby--;
				}//�Ķ����̵�

				if (temp.rx == temp.bx&&conry == conby) {
					if (temp.ry < temp.by) {
						conby++;
					}
					else {
						conry++;
					}
				}//�������� ��ǥ ����

				if (temp.bh == 0 && temp.rh == 1) {
					cout << temp.cnt + 1 << '\n';
					return 0;
				}//�������� ���ۿ� ���� �� cnt���

				if (temp.bh == 0 && temp.rh == 0) {
					temp.cnt++;
					temp.ry = conry;
					temp.by = conby;
					q.push(temp);
				}
			}
			///////////////////�������� �̵�
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
			///////////////////�������� �̵�
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