#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1010

int N, M;
int adj[MAX][MAX];
vector<int> cnt;

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	cnt = vector<int>(N + 1, 0);
	int t, t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d", &t);
		if (t == 0) continue;
		scanf("%d", &t1);
		for (int j = 1; j < t; j++) {
			scanf("%d", &t2);
			if (!adj[t1][t2]) {
				adj[t1][t2] = 1;
				cnt[t2]++;
			}
			t1 = t2;
		}
	}

	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0) q.push(i);

	int ch = N;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans.push_back(now);
		ch--;
		for (int i = 1; i <= N; i++) {
			if (adj[now][i] == 1) {
				cnt[i]--;
				if (cnt[i] == 0)
					q.push(i);
			}
		}
	}

	if (ch == 0)
		for (int a : ans) printf("%d\n", a);
	else
		printf("0");
	return 0;
}