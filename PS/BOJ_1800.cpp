#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1000000000
vector<vector<pair<int, int>>> adj;
vector<int> back;
vector<int> dist;
struct comp {
	bool operator()(pair<int, int> A, pair<int, int> B) {
		return A.second < B.second;
	}
};
int main() {

	int N, P, K;
	int s, e, w;

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &P, &K);
	adj.resize(N + 1);
	back.resize(N + 1);
	dist.resize(N + 1, INF);

	for (int i = 0; i < P; i++) {
		scanf("%d %d %d", &s, &e, &w);
		adj[s].push_back({ e, w });
		adj[e].push_back({ s, w });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

	pq.push({ 1, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;

		for (auto k : adj[now]) {
			
		}
	}
}