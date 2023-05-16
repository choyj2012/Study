#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

vector<pair<int, int>> applist;
int N, M;
int cSum;
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	applist.assign(N, pair<int, int>());

	for (int i = 0; i < N; i++) scanf("%d", &applist[i].first);
	for (int i = 0; i < N; i++) {
		scanf("%d", &applist[i].second);
		cSum += applist[i].second;
	}

	vector<int> dp(cSum+1, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = cSum; j >= applist[i].second; j--) {
			dp[j] = max(dp[j], dp[j - applist[i].second] + applist[i].first);
		}
	}

	for (int i = 0; i <= cSum; i++) {
		if (dp[i] >= M) {
			printf("%d", i);
			return 0;
		}
	}
}