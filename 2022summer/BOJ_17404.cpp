#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1010
#define INF 987654321

int N;
int cost[MAX][3];

int test(int s);
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	int ans = INF;
	for (int i = 0; i < 3; i++) {
		ans = min(ans, test(i));
	}

	printf("%d", ans);
	return 0;
}

int test(int s) {

	vector<vector<int>> dp(N + 1, vector<int>(3, INF));
	dp[0][s] = cost[0][s];

	for (int i = 1; i < N; i++) {

		for (int j = 0; j < 3; j++) {
			
			dp[i][j] = cost[i][j] + 
				min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
		}
	}

	return min(dp[N - 1][(s + 1) % 3], dp[N - 1][(s + 2) % 3]);
}