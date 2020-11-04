#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int U;
	int UL;
	int L;
};

int main() {

	freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);
	vector<vector<int>> map(N, vector<int>(N, 0));
	vector<vector<pos>> dp(N, vector<pos>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	dp[0][1].L = 1;
	int x = 1;
	int y = 0;

	while (1) {

		if (++x == N) {
			x = 0;
			y++;
			if (y == N) break;
		}

		if (map[y][x] == 1) continue;

		if (y - 1 >= 0 && map[y - 1][x] == 0) {
			dp[y][x].U = dp[y - 1][x].U + dp[y - 1][x].UL;
		}

		if (x - 1 >= 0 && map[y][x - 1] == 0) {
			dp[y][x].L = dp[y][x - 1].L + dp[y][x - 1].UL;
		}

		if (y - 1 >= 0 && x - 1 >= 0 && map[y - 1][x - 1] == 0 &&
			map[y - 1][x] == 0 && map[y][x - 1] == 0) {
			dp[y][x].UL = dp[y - 1][x - 1].U + dp[y - 1][x - 1].L + dp[y - 1][x - 1].UL;
		}
	}

	int answer = dp[N - 1][N - 1].U + dp[N - 1][N - 1].L + dp[N - 1][N - 1].UL;

	printf("%d", answer);
	return 0;
}