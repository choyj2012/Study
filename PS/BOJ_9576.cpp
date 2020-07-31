#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> stu;
vector<bool> visited;

int N, M;
int cnt;

void bipare();
bool dfs(int node);

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	while (T--) {

		scanf("%d %d", &N, &M);
		int s, e;
		adj = vector<vector<int>>(N + 2);
		for (int i = 1; i <= M; i++) {
			scanf("%d %d", &s, &e);
			for (int j = s; j <= e; j++) {
				adj[j].push_back(i);
			}
		}
		cnt = 0;
		bipare();
		printf("%d\n", cnt);
	}
}

void bipare() {
	stu = vector<int>(M + 2, -1);
	for (int k = 1; k <= N; k++) {
		visited = vector<bool>(M + 1, false);
		if (dfs(k))
			cnt++;
	}
}

bool dfs(int node) {
	for (int a = 0; a < adj[node].size(); a++) {
		int tmp = adj[node][a];
		if (visited[tmp])continue;
		visited[tmp] = true;

		if (stu[tmp] == -1 || dfs(stu[tmp])) {
			stu[tmp] = node;
			return true;
		}
	}

	return false;
}