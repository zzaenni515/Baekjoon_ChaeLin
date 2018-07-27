//3190-��
#include <iostream>
#include<list>
using namespace std;

int map[100][100] = { 0 };
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };//(0:��,1:������,2:�Ʒ�,3:����)
int n;//�� ũ��(2~100)
int k;//��� ����(0~100)
int kr, kc;//����� ��,��
int l;//���� ���⺯ȯ ����(1~100)
int x;//�����Ŀ� ������ȯ�Ұ��� �� ��.
char c;//L(��)�Ǵ�D(��)
typedef pair<int, int> IIpair;
typedef pair<int, char> ICpair;

int main() {
	cin >> n;//��ũ��
	cin >> k;//�������

	for (int i = 0; i < k; i++) {
		cin >> kr >> kc;
		map[kr - 1][kc - 1] = 2;
	}//����ִ��ڸ��� 2�� ǥ��.

	cin >> l;//���� ���⺯ȯ ���� �Է�.
	ICpair moving[100];

	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		moving[i] = make_pair(x, c);//������ ����.
	}

	list<IIpair> snake;
	snake.push_front(make_pair(0, 0));
	map[0][0] = 1;//����ġ �ʱ�ȭ.

	int dir = 1, hc = 0, hr = 0, move = 0;
	int t = 1;
	while (1) {
		int nr = hr + dr[dir];
		int nc = hc + dc[dir];

		if (nc < 0 || nc >= n || nr < 0 || nr >= n || map[nr][nc] == 1)
			break;
		if (map[nr][nc] == 0) {//��������� ��������.
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		map[nr][nc] = 1;//����ĭ�� �Ӹ� �ø��� �ǹ�.
		snake.push_front(make_pair(nr, nc));
		hr = nr;
		hc = nc;//�Ӹ��� ��, �� ����.

		if (move < l&&moving[move].first == t) {
			dir = (dir + (moving[move++].second == 'L' ? 3 : 1)) % 4;
		}
		t++;
	}
	printf("%d\n", t);
}