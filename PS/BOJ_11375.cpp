#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_SIZE 1002

vector<vector<int>> adj(MAX_SIZE);
//vector<int> worker(MAX_SIZE);
vector<int> work(MAX_SIZE);
vector<bool> visited(MAX_SIZE);

int n, m;
int t, w;
int answer = 0;

bool dfs(int node);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			scanf("%d", &w);
			adj[i].push_back(w);
		}
	}

//	fill(worker.begin(), worker.end(), -1);
	fill(work.begin(), work.end(), -1);

	for (int i = 1; i <= n; i++) {
		//if (worker[i] == -1)
		{
			fill(visited.begin(), visited.end(), false);
			if (dfs(i)) answer++;
		}
	}

	printf("%d", answer);
	return 0;
}

bool dfs(int node) {

	visited[node] = 1;

	for (auto &k : adj[node]){

		if (work[k] == -1 || (!visited[work[k]] && dfs(work[k]))) {
//			worker[node] = k;
			work[k] = node;
			return true;
		}
	}
	return false;
}