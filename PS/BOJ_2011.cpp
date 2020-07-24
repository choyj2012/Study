#include <stdio.h>

#define MOD 1000000
char str[5010];
int dp[5010];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%s", str);

	dp[0] = 1;
	dp[1] = 1;
	if (str[0] == '0') {
		printf("0\n");
		return 0;
	}
	int i;
	for (i = 1; str[i] != '\0'; i++) {

		int p = str[i - 1] - '0';
		int n = str[i] - '0';

		if (n == 0 && p != 1 && p != 2) {
			printf("0\n");
			return 0;
		}

		if (n == 0) dp[i + 1] = dp[i - 1];
		else if (p == 0) dp[i + 1] = dp[i];
		else if (10 * p + n <= 26) {
			dp[i + 1] = dp[i - 1] + dp[i];
		}
		else
			dp[i + 1] = dp[i];

		dp[i + 1] %= MOD;
	}

	printf("%d\n", dp[i]);
	return 0;
}