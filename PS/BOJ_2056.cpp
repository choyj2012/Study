#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	
	int N;
	scanf("%d", &N);

	vector<int> TIME(N + 1);
	vector<vector<int>> adj(N + 1, vector<int>());
	vector<int> indeg(N + 1);

	int t;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &TIME[i], &indeg[i]);

		for (int j = 0; j < indeg[i]; j++) {
			scanf("%d", &t);
			adj[t].push_back(i);
		}
	}

	vector<int> ans(N+1, 0);
	deque<int> Q;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			Q.push_front(i);
	}

	int answer = 0;

	while (!Q.empty()) {

		int now = Q.back();
		Q.pop_back();
		ans[now] += TIME[now];
		answer = max(answer, ans[now]);

		for (int k : adj[now]) {
			if (--indeg[k] == 0) {
				Q.push_front(k);	
			}
			ans[k] = max(ans[k], ans[now]);
		}
	}

	printf("%d", answer);
	return 0;
}