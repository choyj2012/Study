#include <stdio.h>

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, answer = 0;
	int i, j, n, m;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {

		scanf("%d", &n);
		for (j = 1; j <= n; j++) {
			scanf("%d", &m);
			answer = answer ^ m;
		}
		printf("Case #%d\n", i);
		printf("%d", answer);
		answer = 0;
	}
	return 0;
}