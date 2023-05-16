#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX 32001
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

	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0) q.push(i);

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		printf("%d ", n);

		for (int t : adj[n]) {
			cnt[t]--;
			if (cnt[t] == 0)
				q.push(t);
		}
	}

	return 0;
}