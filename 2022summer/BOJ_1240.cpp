#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> adj[1001];

int bfs(int s, int e) {
	queue<pair<int, int>> q;
	vector<bool> check(N + 1, false);
	q.push({ s, 0 });
	check[s] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int d = q.front().second;
		q.pop();

		if (now == e) return d;

		for (auto p : adj[now]) {
			int to = p.first;
			int w = p.second;
			if (check[to]) continue;

			q.push({ to, d + w });
			check[to] = true;
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	int t1, t2, t3;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		adj[t1].push_back({ t2,t3 });
		adj[t2].push_back({ t1,t3 });
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &t1, &t2);
		printf("%d\n", bfs(t1, t2));
	}

	return 0;
}