#include<iostream>
#include<vector>
using namespace std;

int map[101][101];	//이동점 체크하기위한 2차원 배열

int main(int argc, char** argv)
{
	int N;	//드래콘커브 갯수
	int x, y, d, g;
	int result = 0;
	cin >> N;

	for (int test = 0; test < N; test++)
	{
		cin >> x >> y >> d >> g;	//시작좌표, 방향, 세대 입력
	
		vector<int> dragon;
		dragon.push_back(d);	//방향 벡터에 저장

		for (int i = 1; i <= g; i++){	//입력한 세대만큼 반복
			int len = dragon.size();
			for (int j = len - 1; j >= 0; j--){	//이전세대의 길이만큼 반복(역순)
				dragon.push_back((dragon[j] + 1) % 4);	//규칙(이전세대 정보의 역순으로 각 원소 +1 %4
			}
		}

		map[x][y] = 1;	//시작점 체크
		for (int i = 0; i < dragon.size(); i++){	//위에서 계산한 길이만큼 체크
			if (dragon[i] == 0){	//오른쪽
				map[++x][y] = 1;
			}
			else if (dragon[i] == 1){	//위쪽
				map[x][--y] = 1;
			}
			else if (dragon[i] == 2){	//왼쪽
				map[--x][y] = 1;
			}
			else if (dragon[i] == 3){	//아래쪽
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