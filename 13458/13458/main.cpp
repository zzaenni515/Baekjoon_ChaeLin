//13458-시험 감독
#include<iostream>
using namespace std;

int N, B, C;
long long result;
long long totalresult = 0;
long long A[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		result = 0;
		if (A[i] <= B)
			result = 1;
		else if (A[i] <= (B + C))
			result = 2;
		else if (A[i] >(B + C)) {
			result = 2;
			A[i] -= (B + C);
			/*while (A[i] > 0) {
			result += 1;
			A[i] -= C;
			if (A[i] <= 0)
			break;
			else if ((A[i] / C == 0) && (A[i] % C < C)) {
			result += 1;
			break;
			}
			}*/
			long long a = A[i] / C;
			long long b = A[i] % C;
			if (a > 0 && b > 0)
				result = result + a + 1;
			else if (a == 0 && b > 0)
				result = result + 1;
			else
				result = result + a;
		}
		totalresult += result;
	}

	cout << totalresult << '\n';
	return 0;
}