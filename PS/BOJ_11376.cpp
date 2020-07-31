#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> work;
vector<bool> visited;

int n, m;
int t, w;
int answer = 0;

bool dfs(int node);
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	adj.resize(2 * n + 1);
	work.resize(m + 1);
	visited.resize(2 * n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			scanf("%d", &w);
			adj[i].push_back(w);
			adj[i + n].push_back(w);
		}
	}

	fill(work.begin(), work.end(), -1);

	for (int i = 1; i <= 2 * n; i++) {
		
		fill(visited.begin(), visited.end(), false);
		if (dfs(i)) answer++;
	}

	printf("%d", answer);
	return 0;
}

bool dfs(int node) {

	visited[node] = true;

	for (auto& k : adj[node]) {

		if (work[k] == -1 || (!visited[work[k]] && dfs(work[k]))) {
			work[k] = node;
			return true;
		}
	}
	return false;
}