#include<iostream>
using namespace std;
int N, M;
int map[52][52];
int clean_area;
//D->0:��, 1:��, 2:��, 3:��
int dir_r[4] = { -1, 0, 1, 0 };
int dir_c[4] = { 0, 1, 0, -1 };

int clean(int r, int c, int d){
	if (map[r][c] == 1)	//�̵��� ��ġ�� ���� ��� �۵� ����.
		return 0;
	
	if (map[r][c] == 0){	//�̵��� ��ġ�� û�Ұ� �ȵǾ� ���� ��� û���ϱ�(1)
		map[r][c] = 7;
		clean_area++;
	}

	for (int i = 0; i < 4; i++){	//������ġ û������ ���� ��ġ�� ��->��->��->�� Ž���ϱ� ���� �ݺ���
		int next_d = (d + 3)% 4;	//�������� ����.
		int next_r = r + dir_r[next_d];
		int next_c = c + dir_c[next_d];

		if (map[next_r][next_c] == 0){	//ȸ���Ͽ� ������ �ڸ��� û�ҾȵǾ� ������ ���(2-1)
			clean(next_r, next_c, next_d);
			return 0;
		}
		else	//û�ҵ��ְų� ���ΰ��
			d = next_d;	//ȸ���� ���� ���� ��ä ��� Ž��	(2-2)
	}
		
	//��� ���� Ž���� ��-->4���� ��� û�ҵ��ְų� ���� �����.
	//2-3(����)
	if (d == 0) r++;
	else if (d == 1) c--;
	else if (d == 2) r--;
	else if (d == 3) c++;
	
	clean(r, c, d);	//������ �� ��� ����-> �ڰ� ���̸� �۵� �������.
	return 0;
}

int main(){
	int R, C, D;
	cin >> N >> M;	//���ΰ��� �Է�

	cin >> R >> C>> D;//�κ�û�ұ��� �ʱ� ��ġ���� ���� �Է�

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];	//map���� �Է�(0:��ĭ, 1:��)
		}
	}
	clean_area = 0;
	clean(R, C, D);

	cout << clean_area << endl;
	return 0;
}