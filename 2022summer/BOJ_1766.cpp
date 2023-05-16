#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX	32001

int N, M;
vector<int> adj[MAX];
vector<int> cnt;


int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	cnt.resize(N + 1, 0);
	int t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &t1, &t2);
		adj[t1].push_back(t2);
		cnt[t2]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0) pq.push(i);

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		printf("%d ", now);

		for (int t : adj[now]) {
			cnt[t]--;
			if (cnt[t] == 0) pq.push(t);
		}
	}
	return 0;
}