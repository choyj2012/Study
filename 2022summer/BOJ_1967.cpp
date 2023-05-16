#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> adj[10010];
vector<int> check;

void dfs(int s) {
	for (auto p : adj[s]) {
		int to = p.first;
		int w = p.second;

		if (check[to] == -1) {
			check[to] = check[s] + w;
			dfs(to);
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	if (N == 1) {
		printf("0");
		return 0;
	}
	int t1, t2, t3;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		adj[t1].push_back({ t2, t3 });
		adj[t2].push_back({ t1, t3 });
	}

	check.resize(N + 1, -1);
	check[1] = 0;
	dfs(1);
	
	int m = 1;
	for (int i = 1; i <= N; i++) {
		m = (check[m] < check[i]) ? i : m;
	}

	fill(check.begin(), check.end(), -1);
	check[m] = 0;
	dfs(m);
	for (int i = 1; i <= N; i++) {
		m = (check[m] < check[i]) ? i : m;
	}
	printf("%d", check[m]);
	return 0;
}