//9095-1,2,3 ���ϱ�
#include<iostream>
using namespace std;
int d[11];

int main() {
	int t, n;
	d[0] = 1;

	cin >> t;//test case �� �Է�

	for (int i = 1; i <= 10; i++) {//�Է���n(1~10)
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}
	while (t--) {
		int n;
		cin >> n;
		printf("%d\n", d[n]);
	}
}