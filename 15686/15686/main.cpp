#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, result;
int map[51][51];	//도시 map
int check[50];
vector<pair<int, int>> house;	//집 위치 저장벡터
vector<pair<int, int>> chicken;	//치킨집 위치 저장벡터


int dfs(int index, int count){
	if (index > chicken.size()) return 0;	//도시에 존재하는 치킨집 갯수보다 index가 크면 종료.

	if (count == M){	//M개 찾았을 경우
		int total_distance = 0;

		for (int i = 0; i < house.size(); i++){	//집마다 최소 거리 구하는 반복문
			int distance = 999999999;

			for (int j = 0; check[j] != -1; j++){	
				int house_R = house[i].first;
				int house_C = house[i].second;
				int chicken_R = chicken[check[j]].first;
				int chicken_C = chicken[check[j]].second;

				distance = min(distance, abs(house_R - chicken_R) + abs(house_C - chicken_C));	//치킨 거리
			}
			total_distance += distance;	//도시의 치킨 거리 구하기
		}
		result = min(result, total_distance);
		return 0;
	}
	
	//index번째 치킨집 살려둘 경우
	check[count] = index;
	dfs(index + 1, count + 1);
	check[count] = -1;

	//index번째 치킨집 없앨 경우
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

			if (map[i][j] == 1){	//집 좌표 저장
				house.push_back(make_pair(i, j));
			}
			else if(map[i][j] == 2){	//치킨집 좌표 저장
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);
	cout << result;

	return 0;
}