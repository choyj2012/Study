#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> work;
vector<bool> visited;

int n, m, k;
int t, w, cnt = 0;
int answer = 0;

bool dfs(int node);
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
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

	for (int i = 1; i <= n; i++) {
		fill(visited.begin(), visited.end(), false);
		if (dfs(i)) answer++;
	}

	for (int i = n + 1; i <= 2 * n && cnt != k; i++) {
		fill(visited.begin(), visited.end(), false);
		if (dfs(i)) {
			answer++;
			cnt++;
		}
	}

	printf("%d", answer);
	return 0;
}

bool dfs(int node) {
	visited[node] = true;

	for (auto &it : adj[node]) {
		if (work[it] == -1 || (!visited[work[it]] && dfs(work[it]))) {
			work[it] = node;
			return true;
		}
	}
	return false;
}