#include <stdio.h>
#define N 1000010
#define INF 987654321

int answer[N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	scanf("%d", &n);

	answer[1] = 0;
	for (i = 2; i <= n; i++) {
		int min = INF;
		if (i % 2 == 0) {
			min = (min > answer[i / 2]) ? answer[i / 2] : min;
		}
		if (i % 3 == 0) {
			min = (min > answer[i / 3]) ? answer[i / 3] : min;
		}
		min = (min > answer[i - 1]) ? answer[i - 1] : min;

		answer[i] = min + 1;
	}

	printf("%d", answer[n]);
	return 0;
}