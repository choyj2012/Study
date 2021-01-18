#include <cstdio>
#include <vector>
using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	vector<int> num(N + 1, 1<<20);
	vector<int> memo(N + 1, 0);

	num[1] = 0;
	memo[1] = 0;

	for (int i = 2; i <= N; i++) {

		if (i % 2 == 0 && num[i] > num[i / 2]) {
			num[i] = num[i / 2];
			memo[i] = i / 2;
		}

		if (i % 3 == 0 && num[i] > num[i / 3]) {
			num[i] = num[i / 3];
			memo[i] = i / 3;
		}

		if (num[i] > num[i - 1]) {
			num[i] = num[i - 1];
			memo[i] = i - 1;
		}

		num[i]++;
	}

	printf("%d\n", num[N]);

	int k = N;
	while (k != 0) {
		printf("%d ", k);
		k = memo[k];
	}
	return 0;
}