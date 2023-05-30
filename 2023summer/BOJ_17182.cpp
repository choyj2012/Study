#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 11
#define INF 987654321

int N, S;
int D[MAX][MAX];
int dist[MAX][1 << MAX];

void dfs(int n, int check) {
	for (int i = 0; i < N; i++) {
		if (dist[i][check | (1 << i)] > dist[n][check] + D[n][i]) {
			dist[i][check | (1 << i)] = dist[n][check] + D[n][i];
			dfs(i, check | (1 << i));
		}
	}
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> D[i][j];
		}
	}

	fill(&dist[0][0], &dist[0][0] + MAX * (1 << MAX), INF);
	dist[S][1<<S] = 0;
	dfs(S, 1<<S);

	int ans = INF;
	for (int i = 0; i < N; i++) {
		ans = min(ans, dist[i][(1 << N) - 1]);
	}
	cout << ans << "\n";
	return 0;
}