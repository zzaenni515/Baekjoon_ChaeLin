//11727-2xn Ÿ�ϸ�2
#include<iostream>
using namespace std;

int main() {
	int n;
	int d[1001];
	cin >> n;//2xn�簢��

	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + (2 * d[i - 2]);
		d[i] = d[i] % 10007;
	}
	printf("%d", d[n]);
	return 0;
}