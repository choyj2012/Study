#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int main() {

	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	while (T--) {

		int bn, rn;
		scanf("%d %d", &bn, &rn);

		vector<int> bt(bn + 1);
		vector<int> indeg(bn + 1, 0);
		vector<vector<int>> adj(bn + 1, vector<int>());
		int s, e, target;
		for (int i = 1; i <= bn; i++) scanf("%d", &bt[i]);
		for (int i = 0; i < rn; i++) {
			scanf("%d %d", &s, &e);
			adj[s].push_back(e);
			indeg[e]++;
		}
		scanf("%d", &target);

		vector<int> answer(bn + 1, 0);
		deque<int> Q;

		for (int i = 1; i <= bn; i++) {
			if (indeg[i] == 0)
				Q.push_front(i);
		}

		while (!Q.empty()) {

			int now = Q.back();
			answer[now] += bt[now];

			if (now == target) break;
			Q.pop_back();

			for (int k : adj[now]) {
				if (--indeg[k] == 0)
					Q.push_front(k);

				answer[k] = max(answer[k], answer[now]);
			}

		}

		printf("%d\n", answer[target]);
	}
}