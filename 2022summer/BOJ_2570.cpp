#include <cstdio>
#include <vector>
using namespace std;

#define MAX 101
#define MAXN 5010

int map[MAX][MAX];
int N, M;
vector<int> adj[MAXN];
vector<int> left(MAXN, -1);
vector<int> right(MAXN, -1);
vector<bool> visit(MAXN, false);
int inc, dec;

void make_adj() {
	int y, x, pre = -1;
	for (int i = 1; i < 2 * N; i++) {
		y = i; x = 1;
		if (y >= N) {
			x += (y - N);
			y = N;
		}
		while (0 < y && y <= N && 0 < x && x <= N) {
			if (map[y][x] != -1) {
				if (pre == -1) inc++;
				map[y][x] = inc;
			}
			pre = map[y][x];
			x++; y--;
		}
		pre = -1;
	}

	for (int i = 1; i < 2 * N; i++) {
		y = N; x = i;
		if (x >= N) {
			y -= (x - N);
			x = N;
		}
		while (0 < y && y <= N && 0 < x && x <= N) {
			if (map[y][x] != -1) {
				if (pre == -1) dec++;
				adj[map[y][x]].push_back(dec);
			}
			pre = map[y][x];
			x--; y--;
		}
		pre = -1;
	}
}
bool dfs(int now) {
	visit[now] = true;
	for (int next : adj[now]) {
		if (right[next] == -1 || (!visit[right[next]] && dfs(right[next]))) {
			left[now] = next;
			right[next] = now;
			return true;
		}
	}
	return false;
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	int t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &t1, &t2);
		map[t1][t2] = -1;
	}

	make_adj();

	int match = 0;
	for (int i = 1; i <= inc; i++) {
		fill(visit.begin(), visit.end(), false);
		if (dfs(i)) match++;
	}

	printf("%d", match);
	return 0;
}