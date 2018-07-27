//1260-dfs와 bfs
#include<iostream>
#include <queue>
#include<stack>
#include <algorithm>
using namespace std;
int g[1001][1001];
int n, m, v;//n:정점갯수,m:간선갯수,v:탐색시작할 정점 번호
int a, b;//이어진 각각의 정점

void bfs() {
	queue<int> q;
	bool check[1001];
	int path[1000];
	int length = 0;
	fill(&check[0], &check[n + 1], false);
	q.push(v);//시작점push

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (check[now] == false) {
			check[now] = true;
			path[length++] = now;

			for (int i = 1; i <= n; i++)
			{
				if (g[now][i] == 1 && check[i] == false) //If connection & not passed 
				{
					q.push(i); //push 
				}
			}

		}
	}
	for (int i = 0; i < length; i++)
		printf("%d ", path[i]);
	printf("\n");
}

void dfs() {
	stack<int> s;
	bool check[1001];
	int path[1000];
	int lengh = 0;
	fill(&check[0], &check[n + 1], false);
	s.push(v);

	while (!s.empty()) {
		int now = s.top();
		s.pop();

		if (check[now] == false) {
			check[now] = true;
			path[lengh++] = now;
			for (int i = n; i >= 1; i--) {
				if (g[now][i] == 1 && check[i] == false){
					s.push(i);
				}
			}
		}

	}
	for (int i = 0; i < lengh; i++) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

int main() {

	cin >> n >> m >> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = 0;
			g[j][i] = 0;
		}
	}//초기화

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}//연결된노드 확인

	dfs();
	bfs();
	return 0;
}