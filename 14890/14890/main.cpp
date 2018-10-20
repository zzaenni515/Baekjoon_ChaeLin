#include<iostream>
#include<algorithm>
using namespace std;
int N, L;
int map[101][101];
int b[101][101];	//map의 행,열을 바꾼 배열
int ans;

void check(int row, int a[101][101]) {
	bool c[101] = { false, };
	int temp = a[row][0];

	for (int i = 0; i < N; i++) {
		if (a[row][i] != temp) {	//높이가 차이날 경우
			if (abs(a[row][i] - temp) > 1) //차이가 1보다 클경우
				return; //경사로 놓지 못하므로 return

			if (a[row][i] < temp) { //다음것이 나보다 작을 경우(오른쪽 경사로>)
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
				if (i >= N) break;	//경사로를 놓을 때 범위 초과하면 break
			}
			else { //다음것이 나보다 큰 경우(왼쪽 경사로<)
				int num = -1;
				for (int j = i - 1; j >= i - L; j--) {
					if (j < 0 || c[j]) return;	//범위 벗어날 경우 이거나 이미 경사로를 놓은 곳이면 return
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
	++ans;	//이까지 오면 지나갈수 있는 길이기 때문에 갯수++
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