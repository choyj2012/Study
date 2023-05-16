#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int N, M, X;
vector<pair<int, int>> adj[1010];
vector<pair<int, int>> radj[1010];
vector<int> dijk(int start, vector<pair<int, int>> adj[]);
struct cmp {
	bool operator()(pair<int, int> i, pair<int, int> j) {
		if (i.second < j.second) return true;
		return false;
	}
};

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &X);
	int t1, t2, t3;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		adj[t1].push_back({ t2, t3 });
		radj[t2].push_back({ t1, t3 });
	}

	vector<int> d1 = dijk(X, adj);
	vector<int> d2 = dijk(X, radj);

	int ans = d1[1]+d2[1];
	for (int i = 2; i <= N; i++) {
		ans = (d1[i] + d2[i] > ans) ? (d1[i]+d2[i]) : ans;
	}

	printf("%d", ans);
	return 0;
}

vector<int> dijk(int start, vector<pair<int, int>> adj[]) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int to = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[to] < cost) continue;

		for (auto t : adj[to]) {
			int next = t.first;
			int w = t.second;

			if (dist[next] > dist[to] + w) {
				dist[next] = dist[to] + w;
				pq.push({ next, dist[to] + w });
			}
		}
	}

	return dist;
}