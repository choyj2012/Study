#include <stdio.h>

#define MOD 10007

int ans[1001][10];
int n;
int answer;

int main() {

	scanf("%d", &n);
	for (int i = 0; i <= 9; i++) {
		ans[1][i] = 1;
	}
	answer = 10;

	for (int i = 2; i <= n; i++) {
		answer = 0;
		for (int j = 0; j <= 9; j++) {
			if (j == 0) ans[i][j] = 1;
			else ans[i][j] = (ans[i][j - 1] + ans[i - 1][j]) % MOD;

			if (i == n)
				answer = (answer + ans[i][j]) % MOD;
		}
	}

	printf("%d", answer);
	return 0;
}