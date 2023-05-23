#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int Kind, Sum;
int cost;
int dp[10001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	fill(&dp[0], &dp[0] + 10001, INF);

	dp[0] = 0;
	cin >> Kind >> Sum;
	for (int i = 0; i < Kind; i++) {
		cin >> cost;
		for (int i = cost; i <= Sum; i++) {
			dp[i] = min(dp[i], dp[i - cost] + 1);
		}
	}

	if (dp[Sum] == INF) cout << -1 << '\n';
	else cout << dp[Sum] << '\n';
	return 0;
}