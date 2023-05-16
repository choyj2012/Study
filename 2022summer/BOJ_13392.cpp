#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001
#define INF 987654321
int N;
vector<int> be(MAX);
vector<int> af(MAX);
vector<vector<int>> dp(MAX, vector<int>(10, INF));

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%1d", &be[i]);
	for (int i = 1; i <= N; i++) scanf("%1d", &af[i]);
	for (int i = 0; i < 10; i++) dp[0][i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			int l = (af[i] - be[i] - j + 20) % 10;
			int r = 10 - l;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + r);
			dp[i][(j + l) % 10] = min(dp[i][(j + l) % 10], dp[i - 1][j] + l);
		}
	}

	int ans = INF;
	for (int i = 0; i < 10; i++) ans = min(ans, dp[N][i]);
	printf("%d", ans);
	return 0;
}