#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 100010

int dp[MAX][5][5];
int dist[5][5] = {
	{ INF, 2, 2, 2, 2 },
	{ INF, 1, 3, 4, 3 },
	{ INF, 3, 1, 3, 4 },
	{ INF, 4, 3, 1, 3 },
	{ INF, 3, 4, 3, 1 }
};

int main() {

	freopen("input.txt", "r", stdin);

	fill(dp[0][0], dp[MAX][0], INF);
	int next;
	int idx = 0;

	dp[0][0][0] = 0;

	while (1) {
		scanf("%d", &next);
		if (next == 0) break;
		idx++;
		for (int a = 0; a < 5; a++) {
			for (int b = 0; b < 5; b++) {
				dp[idx][next][b] = min(dp[idx][next][b], dp[idx - 1][a][b] + dist[a][next]);
				dp[idx][a][next] = min(dp[idx][a][next], dp[idx - 1][a][b] + dist[b][next]);
			}
		}
	}
	int ans = INF;
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			ans = min(ans, dp[idx][a][b]);
		}
	}

	printf("%d", ans);
	return 0;
}