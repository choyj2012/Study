#include <cstdio>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);

	int N, S;
	scanf("%d %d", &N, &S);

	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	int L = 0;
	int R = 0;
	int sum = num[0];
	int ans = 1000001;

	while (L < N) {

		if (sum < S) {
			R++;
			if (R == N) break;
			sum += num[R];
		}
		else {
			ans = min(ans, R - L + 1);
			sum -= num[L];
			L++;
		}

	}

	if (ans > N) ans = 0;

	printf("%d", ans);
	return 0;
}