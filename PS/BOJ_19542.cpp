#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> level;
vector<bool> visited;

int n_node, start, reach;
int cnt = 0;
int answer = 0;

int dfs(int node);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n_node, &start, &reach);
	adj.resize(n_node + 1);
	visited.resize(n_node + 1);
	level.resize(n_node + 1, 1);
	cnt = n_node;

	int s, e;
	for (int i = 1; i < n_node; i++) {
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	dfs(start);

	answer = max(2 * (cnt - 1), 0);
	printf("%d", answer);

	return 0;
}

int dfs(int node) {

	visited[node] = true;

	for (auto& k : adj[node]) {
		if (visited[k] == false)
			level[node] = max(level[node], dfs(k) + 1);
	}

	if (level[node] <= reach) cnt--;
	return level[node];
}