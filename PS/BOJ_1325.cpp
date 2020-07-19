#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

int dfs(int node);
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	ans.resize(n + 1);
	visited.resize(n + 1);
	int t1, t2;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &t1, &t2);
		adj[t2].push_back(t1);
	}
	int Maxx = 0;
	for (int i = 1; i <= n; i++) {
		ans[i] = dfs(i);
		Maxx = (Maxx < ans[i]) ? ans[i] : Maxx;
		visited.clear();
		visited.resize(n + 1, false);
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == Maxx) printf("%d ", i);
	}
	return 0;
}

int dfs(int node) {
	visited[node] = true;
	int cnt = 1;

	for (auto i = adj[node].begin(); i != adj[node].end(); i++) {
		if(visited[*i] == false)
			cnt += dfs(*i);
	}

	return cnt;
}