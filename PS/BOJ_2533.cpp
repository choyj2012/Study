#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, e;
vector<vector<int>> adj;
vector<pair<int, int>> tree;
//first = 현재노트 선택, second = 현재노드 선택x
vector<bool> visited;

pair<int, int> dp(int node);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	adj.resize(n + 1);
	tree.resize(n + 1, { 1, 0 });
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	pair<int, int> answer = dp(1);
	printf("%d", min(answer.first, answer.second));

	return 0;
}

pair<int, int> dp(int node) {

	visited[node] = true;

	for (auto i = adj[node].begin(); i != adj[node].end(); i++) {
		if (visited[*i] == false)
		{
			pair<int, int> tmp = dp(*i);
			tree[node].first += min(tmp.first, tmp.second);
			tree[node].second += tmp.first;
		}
	}

	return tree[node];
}