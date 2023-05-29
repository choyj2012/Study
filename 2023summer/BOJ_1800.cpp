#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
using namespace std;

const int MAX = 1010;
const int INF = 1987654321;

int N, P, K;
int cost[MAX][MAX];
vector<vector<pair<int,int>>> adj(MAX, vector<pair<int, int>>());

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> N >> P >> K;
	fill(&cost[2][0], &cost[0][0] + MAX * MAX, INF);

	int s, e, w;
	for (int i = 0; i < P; i++) {
		cin >> s >> e >> w;
		adj[s].push_back({ e, w });
		adj[e].push_back({ s, w });
	}

	queue<array<int, 3>> Q;
	Q.push({ 0, 1, 0 });	// cost, node, freeCnt;
	
	while (!Q.empty()) {
		int nowCost = Q.front()[0];
		int from = Q.front()[1];
		int freeCnt = Q.front()[2];
		Q.pop();

		for (auto next : adj[from]) {
			int to = next.first;
			int w = next.second;

			//무료 추가 x
			int c = max(nowCost, w);
			if (cost[to][freeCnt] > c) {
				cost[to][freeCnt] = c;
				Q.push({ c, to, freeCnt });
			}

			//무료로 추가
			if (freeCnt+1 <= K && cost[to][freeCnt + 1] > nowCost) {
				cost[to][freeCnt + 1] = nowCost;
				Q.push({ nowCost, to, freeCnt + 1 });
			}
		}
	}

	int ans = INF;
	for (int a : cost[N]) {
		ans = min(ans, a);
	}
	if (ans == INF) ans = -1;
	cout << ans << "\n";
	return 0;
}