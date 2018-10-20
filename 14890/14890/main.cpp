#include<iostream>
#include<algorithm>
using namespace std;
int N, L;
int map[101][101];
int b[101][101];	//map�� ��,���� �ٲ� �迭
int ans;

void check(int row, int a[101][101]) {
	bool c[101] = { false, };
	int temp = a[row][0];

	for (int i = 0; i < N; i++) {
		if (a[row][i] != temp) {	//���̰� ���̳� ���
			if (abs(a[row][i] - temp) > 1) //���̰� 1���� Ŭ���
				return; //���� ���� ���ϹǷ� return

			if (a[row][i] < temp) { //�������� ������ ���� ���(������ ����>)
				int num = -1;
				for (int j = i; j <= i + L - 1; j++) {
					if (j >= N || c[j]) return;
					c[j] = true;
					if (num == -1) {
						num = a[row][j];
						continue;
					}
					if (num != -1 && a[row][j] != num) return;
				}
				i = i + L - 1;
				if (i >= N) break;	//���θ� ���� �� ���� �ʰ��ϸ� break
			}
			else { //�������� ������ ū ���(���� ����<)
				int num = -1;
				for (int j = i - 1; j >= i - L; j--) {
					if (j < 0 || c[j]) return;	//���� ��� ��� �̰ų� �̹� ���θ� ���� ���̸� return
					c[j] = true;
					if (num == -1) {
						num = a[row][j];
						continue;
					}
					if (num != -1 && a[row][j] != num) return;
				}
			}
			temp = a[row][i];
		}
	}
	++ans;	//�̱��� ���� �������� �ִ� ���̱� ������ ����++
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			b[j][i] = map[i][j];
		}
	for (int i = 0; i < N; i++) {
		check(i, map);
		check(i, b);
	}
	cout << ans << endl;
	return 0;
}