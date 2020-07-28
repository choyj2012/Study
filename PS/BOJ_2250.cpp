#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj;
vector<bool> visited;
vector<pair<int, int>> len;
vector<int> check;

int n;
int cnt = 1;
pair<int, int> answer;

void dfs(int node, int lv);
void input();
int find_root();
void update(int lv);

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	input();
	dfs(find_root(), 1);
	
	printf("%d %d", answer.first, answer.second);
	return 0;
}
void input() {
	scanf("%d", &n);
	adj.resize(n + 1);
	visited.resize(n + 1);
	len.resize(n + 1);
	check.resize(n + 1);
	int t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		scanf("%d %d", &adj[t].first, &adj[t].second);
		if (adj[t].first > 0) check[adj[t].first] = 1;
		if (adj[t].second > 0)check[adj[t].second] = 1;
	}
}
int find_root() {
	int root;
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			root = i;
			break;
		}
	}
	return root;
}
void dfs(int node, int lv) {

	visited[node] = true;
	if (adj[node].first == -1 && adj[node].second == -1) {
		update(lv);
		return;
	}

	if (adj[node].first != -1 && visited[adj[node].first] == false)
		dfs(adj[node].first, lv + 1);

	update(lv);

	if (adj[node].second != -1 && visited[adj[node].second] == false)
		dfs(adj[node].second, lv + 1);

	return;
}
void update(int lv) {
	if (len[lv].first == 0)
		len[lv].first = cnt;

	len[lv].second = cnt - len[lv].first + 1;
	cnt++;

	if (answer.second == len[lv].second)
		answer.first = min(answer.first, lv);
	else if (answer.second < len[lv].second) {
		answer.first = lv;
		answer.second = len[lv].second;
	}
	return;
}