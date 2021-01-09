#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

#define MAX_CITY 10001
#define city first
#define weight second

vector<vector<pair<int, int>>> adj(MAX_CITY, vector<pair<int, int>>());


pair<int, int> bfs(int start) {

	deque<int> Q;
	vector<int> dist(MAX_CITY, 0);
	vector<bool> check(MAX_CITY, false);

	Q.push_front(start);
	check[start] = true;

	while (!Q.empty()) {
		int now = Q.back();
		Q.pop_back();

		for (auto k : adj[now]) {
			if (check[k.city] == false) {
				Q.push_front(k.city);
				check[k.city] = true;
				dist[k.city] = dist[now] + k.weight;
			}
		}
	}
	pair<int, int> ans = { 0, 0 };

	for (int i = 1; i < MAX_CITY; i++) {
		if (ans.second < dist[i]) {
			ans.second = dist[i];
			ans.first = i;
		}
	}
	return ans;
}

int main() {

	freopen("input.txt", "r", stdin);
	
	int s, e, w;

	while (scanf("%d %d %d", &s, &e, &w) != EOF) {
		adj[s].push_back({ e, w });
		adj[e].push_back({ s, w });
	}


	printf("%d", bfs(bfs(1).first).second);

	return 0;
}