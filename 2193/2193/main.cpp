//2193-��ģ��
#include<iostream>
using namespace std;

int main() {
	int n;
	long long d[91];
	d[0] = 0;
	d[1] = 1;
	d[2] = 1;
	cin >> n;//n�ڸ���ģ��������Է�
	if (n>2){
		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2];
		}
	}
	printf("%lld", d[n]);
	return 0;
}