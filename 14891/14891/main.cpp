#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int topnee[5][8];

void rotate(int num, int dir){
	int temp;

	if (dir == 1){	//�ð���� ȸ��
		temp = topnee[num][7];
		for (int a = 6; a >= 0; a--){
			topnee[num][a + 1] = topnee[num][a];
		}

		topnee[num][0] = temp;
	}
	else if (dir == -1){	//�ݽð���� ȸ��
		temp = topnee[num][0];

		for (int a = 1; a < 8; a++){
			topnee[num][a - 1] = topnee[num][a];
		}

		topnee[num][7] = temp;
	}
}

int check_left(int num, int dir){
	if (num < 1||num > 4) return 0;	//���̻� ȸ���� ��� ���� ���

	if (topnee[num][2] != topnee[num + 1][6]){//�������� ������ ��ϰ� �ٸ����� ���
		dir = (dir == 1) ? -1 : 1; //����ٲٱ�
		check_left(num - 1, dir);	//���� ���� ��� Ȯ��
		rotate(num, dir);	//���� ��� ������
	}

	return 0;
}

int check_right(int num, int dir){
	if (num < 1 || num > 4) return 0;	//���̻� ȸ���� ��� ���� ���

	if (topnee[num - 1][2] != topnee[num][6]){	//���������� ������ ��ϰ� �ٸ� ���� ���
		dir = (dir == 1) ? -1 : 1;	//����ٲٱ�
		check_right(num + 1, dir);	//���� ������ ��� Ȯ��
		rotate(num, dir);	//���� ��� ������
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
	}	//��� 4�� �Է�

	cin >> k;	//ȸ��Ƚ�� �Է�

	for (int i = 0; i < k; i++){
		cin >> top_num >> top_dir;	//ȸ���� ���, ȸ������ �Է�

		check_left(top_num - 1, top_dir);	//���� ��� ȸ��
		check_right(top_num + 1, top_dir);	//������ ��� ȸ��

		rotate(top_num, top_dir);
	}

	int result = topnee[1][0] + (2*topnee[2][0]) + (4*topnee[3][0]) + (8*topnee[4][0]);
	cout << result << endl;

	return 0;
}