#include<iostream>
#include<vector>
using namespace std;

int map[101][101];	//�̵��� üũ�ϱ����� 2���� �迭

int main(int argc, char** argv)
{
	int N;	//�巡��Ŀ�� ����
	int x, y, d, g;
	int result = 0;
	cin >> N;

	for (int test = 0; test < N; test++)
	{
		cin >> x >> y >> d >> g;	//������ǥ, ����, ���� �Է�
	
		vector<int> dragon;
		dragon.push_back(d);	//���� ���Ϳ� ����

		for (int i = 1; i <= g; i++){	//�Է��� ���븸ŭ �ݺ�
			int len = dragon.size();
			for (int j = len - 1; j >= 0; j--){	//���������� ���̸�ŭ �ݺ�(����)
				dragon.push_back((dragon[j] + 1) % 4);	//��Ģ(�������� ������ �������� �� ���� +1 %4
			}
		}

		map[x][y] = 1;	//������ üũ
		for (int i = 0; i < dragon.size(); i++){	//������ ����� ���̸�ŭ üũ
			if (dragon[i] == 0){	//������
				map[++x][y] = 1;
			}
			else if (dragon[i] == 1){	//����
				map[x][--y] = 1;
			}
			else if (dragon[i] == 2){	//����
				map[--x][y] = 1;
			}
			else if (dragon[i] == 3){	//�Ʒ���
				map[x][++y] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if ((map[i][j] == 1) && (map[i][j + 1] == 1) && (map[i + 1][j] == 1) && (map[i + 1][j + 1] == 1)){
				result++;
			}
		}
	}
	cout << result << endl;

	return 0;
}