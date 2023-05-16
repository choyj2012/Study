#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> ant;
vector<vector<pair<int, int>>> adj;
vector<bool> visit;
vector<int> track;
vector<int> dist;
vector<int> ans;

void dfs(int node);
int bs(int node);

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	adj.resize(N + 1, vector<pair<int, int>>());
	int t;
	ant.push_back(-1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		ant.push_back(t);
	}

	int t1, t2, t3;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		adj[t1].push_back({ t2, t3 });
		adj[t2].push_back({ t1, t3 });
	}

	visit.assign(N + 1, false);
	ans.resize(N + 1);
	dist.resize(N + 1);
	track.push_back(1);
	dist[1] = 0;
	visit[1] = true;
	dfs(1);

	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);

	return 0;
}

void dfs(int node) {

	for (auto p : adj[node]) {
		int next = p.first;
		int w = p.second;

		if (visit[next] == false) {
			visit[next] = true;
			track.push_back(next);
			dist[next] = dist[node] + w;
			dfs(next);
		}
	}

	if (ant[node] >= dist[node]) ans[node] = 1;
	else {
		ans[node] = bs(node);
	}
	track.pop_back();
}

int bs(int node) {

	int lo = 0;
	int hi = track.size() - 1;
	int a = node;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		int cost = dist[node] - dist[track[mid]];
		if (ant[node] >= cost) {
			a = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}

	return track[a];
}