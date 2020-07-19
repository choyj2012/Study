#include <stdio.h>

int T;
int n;
int d[2][100001];
int dp[2][100001];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);

		for (int j = 1; j <= 2*n; j++) {
			scanf("%d", &d[(j - 1) / n][(j-1) % n+1]);
		}

		dp[0][1] = d[0][1];
		dp[1][1] = d[1][1];
		dp[0][2] = d[0][2] + d[1][1];
		dp[1][2] = d[1][2] + d[0][1];

		for (int j = 3; j <= n; j++) {
			dp[0][j] = d[0][j] + ((dp[1][j - 1] > dp[1][j - 2]) ? dp[1][j - 1] : dp[1][j - 2]);
			dp[1][j] = d[1][j] + ((dp[0][j - 1] > dp[0][j - 2]) ? dp[0][j - 1] : dp[0][j - 2]);
		}

		if (dp[1][n] > dp[0][n]) printf("%d\n", dp[1][n]);
		else printf("%d\n", dp[0][n]);
	}
}