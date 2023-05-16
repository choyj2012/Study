#include <cstdio>
#include <vector>
using namespace std;

#define INF 987654321
int T, N, M, W;

struct edge {
	int from;
	int to;
	int cost;
};
bool bell_ford(int s, const vector<edge>& adj);
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	while (T--) {

		scanf("%d %d %d", &N, &M, &W);
		vector<edge> adj;
		int t1, t2, t3;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &t1, &t2, &t3);
			adj.push_back({ t1, t2, t3 });
			adj.push_back({ t2, t1, t3 });
		}
		for (int i = 0; i < W; i++) {
			scanf("%d %d %d", &t1, &t2, &t3);
			adj.push_back({ t1, t2, -t3 });
		}

		bool hasCycle = bell_ford(1, adj);
		if (hasCycle) printf("YES\n");
		else printf("NO\n");
	}
}

bool bell_ford(int s, const vector<edge>& adj) {

	vector<int> dist(N + 1, INF);
	dist[s] = 0;

	for (int k = 1; k <= N; k++) {

		for (int i = 0; i < 2*M+W; i++) {
			int from = adj[i].from;
			int to = adj[i].to;
			int cost = adj[i].cost;

			//if (dist[from] >= INF) continue;

			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
				if (k == N) return true;
			}
		}

	}

	return false;
}