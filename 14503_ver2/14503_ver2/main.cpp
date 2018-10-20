#include<iostream>
using namespace std;
int N, M;
int map[52][52];
int clean_area;
//D->0:북, 1:동, 2:남, 3:서
int dir_r[4] = { -1, 0, 1, 0 };
int dir_c[4] = { 0, 1, 0, -1 };

int clean(int r, int c, int d){
	if (map[r][c] == 1)	//이동한 위치가 벽일 경우 작동 멈춤.
		return 0;
	
	if (map[r][c] == 0){	//이동한 위치가 청소가 안되어 있을 경우 청소하기(1)
		map[r][c] = 7;
		clean_area++;
	}

	for (int i = 0; i < 4; i++){	//현재위치 청소한후 현재 위치의 동->남->서->북 탐색하기 위한 반복문
		int next_d = (d + 3)% 4;	//다음방향 설정.
		int next_r = r + dir_r[next_d];
		int next_c = c + dir_c[next_d];

		if (map[next_r][next_c] == 0){	//회전하여 전진한 자리가 청소안되어 있으면 재귀(2-1)
			clean(next_r, next_c, next_d);
			return 0;
		}
		else	//청소되있거나 벽인경우
			d = next_d;	//회전한 방향 유지 한채 계속 탐색	(2-2)
	}
		
	//모든 방향 탐색한 후-->4방향 모두 청소되있거나 벽인 경우임.
	//2-3(후진)
	if (d == 0) r++;
	else if (d == 1) c--;
	else if (d == 2) r--;
	else if (d == 3) c++;
	
	clean(r, c, d);	//후진한 후 재귀 돌림-> 뒤가 벽이면 작동 멈출거임.
	return 0;
}

int main(){
	int R, C, D;
	cin >> N >> M;	//세로가로 입력

	cin >> R >> C>> D;//로봇청소기의 초기 위치값과 방향 입력

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];	//map정보 입력(0:빈칸, 1:벽)
		}
	}
	clean_area = 0;
	clean(R, C, D);

	cout << clean_area << endl;
	return 0;
}