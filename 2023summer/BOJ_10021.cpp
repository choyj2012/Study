#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

int N, C;
vector<pair<int, int>> pos;
vector<array<int, 3>> edge;
vector<int> group(2010);

int calCost(const pair<int, int> i, const pair<int, int>& j) {
	return (i.first - j.first)*(i.first - j.first)
		+ (i.second - j.second)*(i.second - j.second);
}

int union_find(int node) {
	if (node == group[node])
		return node;
	else
		return group[node] = union_find(group[node]);
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> N >> C;
	pos.assign(N, pair<int, int>());
	for (auto& p : pos) {
		cin >> p.first >> p.second;
	}

	for (auto i = pos.begin(); i != pos.end(); i++) {
		for (auto j = i + 1; j != pos.end(); j++) {
			edge.push_back({
				i - pos.begin(), j - pos.begin(),
				calCost(*i, *j) });
		}
	}

	sort(edge.begin(), edge.end(),
		[](const array<int, 3>& i, const array<int, 3>& j) {
		return i[2] < j[2];
	});

	int EdgeCnt = 0;
	int answer = 0;
	iota(&group[0], &group[0] + 2010, 0);
	for (auto E : edge) {

		if (E[2] < C) continue;

		int g1 = union_find(E[0]);
		int g2 = union_find(E[1]);

		if (g1 != g2) {
			group[g2] = g1;
			EdgeCnt++;
			answer += E[2];
		}
	}

	if (EdgeCnt == N - 1) cout << answer << "\n";
	else cout << -1 << "\n";
	return 0;
}