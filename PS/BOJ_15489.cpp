#include <stdio.h>

#define N 40

int pas[N][N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);

	int i, j;
	pas[0][0] = 1;
	for (i = 1; i <= 30; i++) {
		for (j = 1; j <= i; j++) {
			pas[i][j] = pas[i - 1][j] + pas[i - 1][j - 1];
		}
	}

	int answer = 0;
	for (i = r; i <= r + w - 1; i++) {
		for (j = c; j <= c + i - r; j++) {
			answer += pas[i][j];
		}
	}

	printf("%d", answer);
	return 0;
}