#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10010;

int islandCnt, bridgeCnt;
vector<vector<pair<int, int>>> bridge(MAX, vector<pair<int, int>>());
int Start, End;
int low, high;
int Answer = -1;

bool bfs(int ans);

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> islandCnt >> bridgeCnt;

	int from, to, weight;
	for (int i = 0; i < bridgeCnt; i++) {
		cin >> from >> to >> weight;
		bridge[from].emplace_back(make_pair(to, weight));
		bridge[to].emplace_back(make_pair(from, weight));
		high = max(high, weight);
	}

	cin >> Start >> End;

	int mid;
	while(low < high) {
		mid = (low + high) / 2 + 1;

		if (bfs(mid)) {
			low = mid;
			Answer = mid;
		}
		else {
			high = mid - 1;
		}
	}

	cout << Answer << '\n';
	return 0;
}

bool bfs(int ans) {

	vector<bool> check(islandCnt + 1, false);
	queue<int> Q;
	Q.push(Start);
	check[Start] = true;

	while (!Q.empty()) {
		int from = Q.front();
		Q.pop();

		if (from == End) return true;

		for (auto bri : bridge[from]) {
			int to = bri.first;
			int w = bri.second;

			if (check[to] || w < ans) continue;
			Q.push(to);
			check[to] = true;
		}
	}

	return false;
}