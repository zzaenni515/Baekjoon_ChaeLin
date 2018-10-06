#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int topnee[5][8];

void rotate(int num, int dir){
	int temp;

	if (dir == 1){	//시계방향 회전
		temp = topnee[num][7];
		for (int a = 6; a >= 0; a--){
			topnee[num][a + 1] = topnee[num][a];
		}

		topnee[num][0] = temp;
	}
	else if (dir == -1){	//반시계방향 회전
		temp = topnee[num][0];

		for (int a = 1; a < 8; a++){
			topnee[num][a - 1] = topnee[num][a];
		}

		topnee[num][7] = temp;
	}
}

int check_left(int num, int dir){
	if (num < 1||num > 4) return 0;	//더이상 회전할 톱니 없는 경우

	if (topnee[num][2] != topnee[num + 1][6]){//왼쪽으로 인접한 톱니가 다른극일 경우
		dir = (dir == 1) ? -1 : 1; //방향바꾸기
		check_left(num - 1, dir);	//다음 왼쪽 톱니 확인
		rotate(num, dir);	//현재 톱니 돌리기
	}

	return 0;
}

int check_right(int num, int dir){
	if (num < 1 || num > 4) return 0;	//더이상 회전할 톱니 없는 경우

	if (topnee[num - 1][2] != topnee[num][6]){	//오른쪽으로 인접한 톱니가 다른 극일 경우
		dir = (dir == 1) ? -1 : 1;	//방향바꾸기
		check_right(num + 1, dir);	//다음 오른쪽 톱니 확인
		rotate(num, dir);	//현재 톱니 돌리기
	}

	return 0;
}

int main(){
	int k, top_num, top_dir;

	for (int i = 1; i < 5; i++){
		for (int j = 0; j < 8; j++){
			//cin >> topnee[i][j];
			scanf("%1d", &topnee[i][j]);
		}
	}	//톱니 4개 입력

	cin >> k;	//회전횟수 입력

	for (int i = 0; i < k; i++){
		cin >> top_num >> top_dir;	//회전할 톱니, 회전방향 입력

		check_left(top_num - 1, top_dir);	//왼쪽 톱니 회전
		check_right(top_num + 1, top_dir);	//오른쪽 톱니 회전

		rotate(top_num, top_dir);
	}

	int result = topnee[1][0] + (2*topnee[2][0]) + (4*topnee[3][0]) + (8*topnee[4][0]);
	cout << result << endl;

	return 0;
}