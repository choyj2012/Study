#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[201][201][201];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, g, b, t;

	scanf("%d %d %d", &r, &g, &b);
	vector<int> R(r);
	vector<int> G(g);
	vector<int> B(b);

	for (int i = 0; i < r; i++) scanf("%d", &R[i]);
	for (int i = 0; i < g; i++) scanf("%d", &G[i]);
	for (int i = 0; i < b; i++) scanf("%d", &B[i]);
	sort(R.rbegin(), R.rend());
	sort(G.rbegin(), G.rend());
	sort(B.rbegin(), B.rend());

	int answer = 0;
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= g; j++) {
			for (int k = 0; k <= b; k++) {
//				if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
//				if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
//				if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);

				if (i > 0 && j > 0)	dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + R[i - 1] * G[j - 1]);
				if (i > 0 && k > 0)	dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + R[i - 1] * B[k - 1]);
				if (j > 0 && k > 0)	dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + G[j - 1] * B[k - 1]);
				answer = max(answer, dp[i][j][k]);
			}
		}
	}
//	printf("%d", dp[r][g][b]);
	printf("%d", answer);
	return 0;
}