#include <stdio.h>

#define MOD (int)1e9

int dp[202][202];
int n, k;
int main() {

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			if (j == 1) dp[i][j] = i;
			else if (i == 1) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

			dp[i][j] %= MOD;
		}
	}

	printf("%d", dp[k][n]);
	return 0;
}