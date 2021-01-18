#include <cstdio>
using namespace std;

#define MOD 1000000000

int dp[101][10][4];

int main() {

	freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {

		if (i == 1) {
			for (int j = 1; j <= 8; j++) {
				dp[i][j][0] = 1;
			}
			dp[i][9][1 << 1] = 1;
		}
		else {

			for (int j = 0; j <= 9; j++) {

				if (j == 0) {
					for (int k = 0; k < 4; k++) {
						dp[i][0][k | (1 << 0)] += dp[i - 1][1][k];
						dp[i][0][k | (1 << 0)] %= MOD;
					}
				}
				else if (j == 9) {
					for (int k = 0; k < 4; k++) {
						dp[i][9][k | (1 << 1)] += dp[i - 1][8][k];
						dp[i][9][k | (1 << 1)] %= MOD;
					}
				}
				else {
					for (int k = 0; k < 4; k++) {
						dp[i][j][k | 0] += dp[i - 1][j + 1][k];
						dp[i][j][k | 0] += dp[i - 1][j - 1][k];
						dp[i][j][k | 0] %= MOD;
					}
				}

			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[N][i][3]) % MOD;
	}
	printf("%d", answer);
	return 0;
}

/*
벽에 닿는 경우에만 bit를 조절.

즉, 9번에 닿으면 bit = 2, 0번에 닿으면 bit = 1
아직 닿지 않은경우 bit = 0 -> 그럼 모두 닿으면 비트 3
0~9까지 모두 포함되려면 두쪽다 닿아야함.

이렇게 하면 d[100][10][4] 만으로도 해결이 가능.
*/