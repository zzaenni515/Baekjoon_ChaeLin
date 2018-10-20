#include<iostream>
using namespace std;

int n = 0, m = 0, h = 0; //세로선, 가로선,가로선 놓을수잇는개수
int arr1[32][12] = { 0 }; //전체 사다리
int result = -1;

void find(int cnt, int total)
{
	if (result != -1)
		return;
	if (cnt >= total)
	{
		for (int i = 1; i <= n; i++)//사다리 확인
		{
			int tmp = i;
			for (int j = 1; j <= h; j++)
			{
				if (arr1[j][tmp] == 0)
					continue;
				if (arr1[j][tmp] > 0)
				{
					if (arr1[j][tmp] == 1)
					{
						tmp++;
						continue;
					}
					else
					{
						tmp--;
						continue;
					}
				}
			}
			if (tmp == i)
				continue;
			else
				return;
		}
		result = total;
		return;
	}
	for (int i = 1; i < n; i++)//사다리 확인
	{
		for (int j = 1; j <= h; j++)
		{
			if ((arr1[j][i] == 0) && (arr1[j][i + 1] == 0))
			{
				arr1[j][i] = 1;
				arr1[j][i + 1] = 2;
				find(cnt + 1, total);
				arr1[j][i] = 0;
				arr1[j][i + 1] = 0;
				continue;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr1[a][b] = 1;
		arr1[a][b + 1] = 2;
	}

	for (int i = 0; i < 4; i++)
	{
		find(0, i);
		if (result != -1)
			break;
	}
	cout << result << endl;
	return 0;
}