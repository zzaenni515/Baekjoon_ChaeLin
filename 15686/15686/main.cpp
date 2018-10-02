#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, result;
int map[51][51];	//���� map
int check[50];
vector<pair<int, int>> house;	//�� ��ġ ���庤��
vector<pair<int, int>> chicken;	//ġŲ�� ��ġ ���庤��


int dfs(int index, int count){
	if (index > chicken.size()) return 0;	//���ÿ� �����ϴ� ġŲ�� �������� index�� ũ�� ����.

	if (count == M){	//M�� ã���� ���
		int total_distance = 0;

		for (int i = 0; i < house.size(); i++){	//������ �ּ� �Ÿ� ���ϴ� �ݺ���
			int distance = 999999999;

			for (int j = 0; check[j] != -1; j++){	
				int house_R = house[i].first;
				int house_C = house[i].second;
				int chicken_R = chicken[check[j]].first;
				int chicken_C = chicken[check[j]].second;

				distance = min(distance, abs(house_R - chicken_R) + abs(house_C - chicken_C));	//ġŲ �Ÿ�
			}
			total_distance += distance;	//������ ġŲ �Ÿ� ���ϱ�
		}
		result = min(result, total_distance);
		return 0;
	}
	
	//index��° ġŲ�� ����� ���
	check[count] = index;
	dfs(index + 1, count + 1);
	check[count] = -1;

	//index��° ġŲ�� ���� ���
	dfs(index + 1, count);

	return 0;
}


int main(){
	result = 999999999;
	for (int a = 0; a < 50; a++) check[a] = -1;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++){ 
		for (int j = 0; j < N; j++){
			cin >> map[i][j];

			if (map[i][j] == 1){	//�� ��ǥ ����
				house.push_back(make_pair(i, j));
			}
			else if(map[i][j] == 2){	//ġŲ�� ��ǥ ����
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);
	cout << result;

	return 0;
}