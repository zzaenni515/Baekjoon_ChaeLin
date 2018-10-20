#include<iostream>
using namespace std;

int map[21][21];
int N, M, X, Y, K;
int dice[7];
int d;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};	//1:동, 2:서, 3:북, 4:남


void move_dice(int d){	//주사위 회전시키는 함수	
	int temp[7];
	for (int i = 0; i < 7; i++) temp[i] = dice[i];	//현재 주사위 정보 복사
	//1:윗면, 6:아랫면

	if (d == 1){	//동쪽
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (d == 2){	//서쪽
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[6] = temp[4];
		dice[4] = temp[1];
	}
	else if (d == 3){	//북쪽
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	else if (d == 4){	//남쪽
		dice[1] = temp[2];
		dice[5] = temp[1];
		dice[6] = temp[5];
		dice[2] = temp[6];
	}
}
int main(){
	cin >> N >> M>> X >> Y >> K;//지도의 세로, 가로, 주사위 위치(행, 열), 명령갯수

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];	//map정보 입력(단, 주사위 초기 위치는 무조건 0입력)
		}
	}
	for (int i = 0; i < 7; i++) dice[i] = 0;	//주사위 초기값 모두 0

	for (int i = 0; i < K; i++){
		cin >> d;	//명령 입력
		int next_x = X + dr[d-1];
		int next_y = Y + dc[d-1];	//다음 위치 구하기(next_x, next_y)

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){	//이동 가능한 map영역인지 확인 후 진행
			move_dice(d);	//주사위 회전&이동
			
			if (map[next_x][next_y] == 0){
				map[next_x][next_y] = dice[6];
			}
			else{
				dice[6] = map[next_x][next_y];	//주사위 밑면에 지도숫자 입력
				map[next_x][next_y] = 0;	//주사위에 복사한 후 지도는 0으로 변경
			}

			X = next_x;
			Y = next_y;
			cout << dice[1] << endl;
		}
	}
}