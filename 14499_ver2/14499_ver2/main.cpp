#include<iostream>
using namespace std;

int map[21][21];
int N, M, X, Y, K;
int dice[7];
int d;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};	//1:��, 2:��, 3:��, 4:��


void move_dice(int d){	//�ֻ��� ȸ����Ű�� �Լ�	
	int temp[7];
	for (int i = 0; i < 7; i++) temp[i] = dice[i];	//���� �ֻ��� ���� ����
	//1:����, 6:�Ʒ���

	if (d == 1){	//����
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (d == 2){	//����
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[6] = temp[4];
		dice[4] = temp[1];
	}
	else if (d == 3){	//����
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	else if (d == 4){	//����
		dice[1] = temp[2];
		dice[5] = temp[1];
		dice[6] = temp[5];
		dice[2] = temp[6];
	}
}
int main(){
	cin >> N >> M>> X >> Y >> K;//������ ����, ����, �ֻ��� ��ġ(��, ��), ��ɰ���

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];	//map���� �Է�(��, �ֻ��� �ʱ� ��ġ�� ������ 0�Է�)
		}
	}
	for (int i = 0; i < 7; i++) dice[i] = 0;	//�ֻ��� �ʱⰪ ��� 0

	for (int i = 0; i < K; i++){
		cin >> d;	//��� �Է�
		int next_x = X + dr[d-1];
		int next_y = Y + dc[d-1];	//���� ��ġ ���ϱ�(next_x, next_y)

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){	//�̵� ������ map�������� Ȯ�� �� ����
			move_dice(d);	//�ֻ��� ȸ��&�̵�
			
			if (map[next_x][next_y] == 0){
				map[next_x][next_y] = dice[6];
			}
			else{
				dice[6] = map[next_x][next_y];	//�ֻ��� �ظ鿡 �������� �Է�
				map[next_x][next_y] = 0;	//�ֻ����� ������ �� ������ 0���� ����
			}

			X = next_x;
			Y = next_y;
			cout << dice[1] << endl;
		}
	}
}