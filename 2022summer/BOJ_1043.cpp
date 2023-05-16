#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M, T;
vector<int> Tlist;
int adj[55][55];
vector<int> plist[55];
vector<int> check;

void bfs() {

	queue<int> q;
	check.resize(N+1, 0);
	for (int a : Tlist) {
		q.push(a);
		check[a] = 1;
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (adj[now][i] == 1 && check[i] != 1) {
				q.push(i);
				check[i] = 1;
			}
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);
	scanf("%d", &T);
	int t;
	for (int i = 0; i < T; i++) {
		scanf("%d", &t);
		Tlist.push_back(t);
	}
	int n, t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		scanf("%d", &t1);
		plist[i].push_back(t1);
		for (int j = 1; j < n; j++) {
			scanf("%d", &t2);
			plist[i].push_back(t2);
			adj[t1][t2] = 1;
			adj[t2][t1] = 1;
			t1 = t2;
		}
	}

	bfs();
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int flag = 0;
		for (int p : plist[i]) {
			if (check[p] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ans++;
	}
	printf("%d", ans);
	return 0;
}