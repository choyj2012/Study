#include <stdio.h>

int answer[13];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int T;
	int n, i;

	for (i = 1; i < 11; i++) {
		if (i <= 3) answer[i]++;
		answer[i] += answer[i - 1];
		if (i - 2 < 0) continue;
		answer[i] += answer[i - 2];
		if (i - 3 < 0)continue;
		answer[i] += answer[i - 3];
	}
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d", &n);
		printf("%d\n", answer[n]);
	}

	return 0;
}