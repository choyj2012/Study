#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

#define INF 987654321
#define MAX 1001

int n_node, n_edge;
vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<int> answer;

int S = 1;
int T = 2;


void dijstra() {
	dist[T] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ T, 0 });

	while (!pq.empty()) {

		int now = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		for (auto& k : adj[now]) {
			if (dist[k.first] > d + k.second) {
				dist[k.first] = d + k.second;
				pq.push({ k.first, d + k.second });
			}
		}
	}
}

vector<vector<int>> new_adj;
void cutting() {

	new_adj.resize(n_node + 1);
	for (int i = 1; i <= n_node; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int there = adj[i][j].first;
			if (dist[i] < dist[there])
				new_adj[i].push_back(there);
		}
	}
}
int dp(int node) {

	if (node == S) return answer[S] = 1;

	for (int i = 0; i < new_adj[node].size(); i++) {
		int there = new_adj[node][i];

		if (dist[node] < dist[there]) {
			if(answer[there] == 0)
				answer[node] += dp(there);
			else answer[node] += answer[there];
		}
	}
	return answer[node];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n_node, &n_edge);
	adj.resize(n_node + 1);
	dist.resize(n_node + 1, INF);
	answer.resize(n_node + 1);

	int s, e, w;
	for (int i = 1; i <= n_edge; i++) {
		scanf("%d %d %d", &s, &e, &w);
		adj[s].push_back({ e,w });
		adj[e].push_back({ s,w });
	}

	dijstra();

	cutting();
	answer[S] = 1;
	answer[T] = dp(T);

	printf("%d", answer[T]);
	return 0;
}