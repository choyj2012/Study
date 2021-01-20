//Knapsack Problem
#include <cstdio>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);

	int N, K;
	scanf("%d %d", &N, &K);

	vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));

	int w, v;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &w, &v);

		for (int j = 1; j <= K; j++) {
			if (j < w) DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w] + v);
		}
	}

	printf("%d", DP[N][K]);
	return 0;
}