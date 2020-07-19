#include <stdio.h>

#define MOD 1000000000
int ans[102][10] = { {0,}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
int n;
int answer = 9;
int main() {

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		answer = 0;
		for (int j = 0; j <= 9; j++) {

			if (j == 0) ans[i][j] = ans[i - 1][1];
			else if (j == 9) ans[i][j] = ans[i - 1][8];
			else
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j + 1];

			ans[i][j] %= MOD;
			if (i == n)
				answer = (answer + ans[i][j]) % MOD;
		}
	}
	
	printf("%d", answer);
	return 0;	
}