#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, Q;
vector<vector<pair<int, int>>> adj;
int bfs(int K, int node);
int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> N >> Q;
	adj.resize(N + 1, vector<pair<int, int>>());
	int s, e, w;
	for (int i = 0; i < N - 1; i++) {
		cin >> s >> e >> w;
		adj[s].push_back({ e, w });
		adj[e].push_back({ s, w });
	}

	int K, start;
	for (int i = 0; i < Q; i++) {
		cin >> K >> start;
		cout << bfs(K, start) << "\n";
	}
}

int bfs(int K, int node) {

	int answer = 0;
	vector<bool> check(N + 1, false);
	deque<int> Q;
	Q.push_back(node);
	check[node] = true;

	while (!Q.empty()) {
		int from = Q.front();
		Q.pop_front();

		for (auto to : adj[from]) {
			if (!check[to.first] && to.second >= K) {
				Q.push_back(to.first);
				check[to.first] = true;
				answer++;
			}
		}
	}

	return answer;
}