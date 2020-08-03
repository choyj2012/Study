#include <cstdio>
#include <vector>
using namespace std;

int n_node, root, n_query;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> sub;

void dfs(int node);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n_node, &root, &n_query);
	adj.resize(n_node + 1);
	visited.resize(n_node + 1);
	sub.resize(n_node + 1, 1);

	int s, e;
	for (int i = 1; i <= n_node - 1; i++) {
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	dfs(root);

	int t;
	for (int i = 1; i <= n_query; i++) {
		scanf("%d", &t);
		printf("%d\n", sub[t]);
	}

	return 0;
}

void dfs(int node) {

	visited[node] = true;

	for (auto& k : adj[node]) {
		if (visited[k] == false) {
			dfs(k);
			sub[node] += sub[k];
		}
	}

	return;
}