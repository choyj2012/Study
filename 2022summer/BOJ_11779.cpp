#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int N, M;
int S, E;
vector<pair<int, int>> adj[1010];
vector<int> dist(N + 1, INF);
vector<int> pre(N + 1);

struct compare {
	bool operator()(pair<int,int> i, pair<int, int> j){
		if (i.second > j.second) return true;
		else return false;
	}
};

void djik(int s) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	dist.resize(N + 1, INF);
	pre.resize(N + 1);
	for (int i = 1; i <= N; i++) pre[i] = i;

	dist[s] = 0;
	pq.push({ s, 0 });

	while (!pq.empty()) {
		int now = pq.top().first;
		int w = pq.top().second;
		pq.pop();

		if (now == E) return;
		if (dist[now] < w) continue;

		dist[now] =  w;


		for (auto t : adj[now]) {
			int to = t.first;
			int tow = t.second;
			if (dist[to] > dist[now] + tow) {
				pq.push({ to, dist[now] + tow });
				dist[to] = dist[now] + tow;
				pre[to] = now;
			}
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	int t1, t2, t3;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		adj[t1].push_back({ t2, t3 });
	}
	scanf("%d %d", &S, &E);
	djik(S);

	printf("%d\n", dist[E]);
	vector<int> ans;
	int node = E;
	while (node != S) {
		ans.push_back(node);
		node = pre[node];
	}
	ans.push_back(S);
	printf("%d\n", ans.size());
	for (auto i = ans.rbegin(); i != ans.rend(); i++) {
		printf("%d ", *i);
	}
	return 0;
}