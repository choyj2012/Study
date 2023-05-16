#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 11

int N;
int m[MAX][MAX];

void init() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &m[i][j]);
		}
	}
}

//sol1
bool inc[25];
bool dec[25];
int max1 = -1;
int max2 = -1;

int track(int y, int x) {

	if (x > N) {
		if (x % 2 == 0) x = 1;
		else x = 2;
		y++;
	}
	if (y > N) return 0;

	int ret = 0;
	if (m[y][x] == 1 && !inc[y + x] && !dec[y - x + N]) {
		inc[y + x] = 1;
		dec[y - x + N] = 1;
		ret = track(y, x + 2) + 1;
		inc[y + x] = 0;
		dec[y - x + N] = 0;
	}
	return max(ret, track(y, x + 2));
}

void sol1_backtracking() {

	max1 = track(1, 1);
	max2 = track(1, 2);
	printf("%d", max1 + max2);
}

//sol2
vector<int> adj[510];
vector<int> left(510, -1);
vector<int> right(510, -1);
vector<bool> visit(510, false);

void make_adj() {
	int y, x;
	for (int i = 1; i < 2 * N; i++) {
		y = i; x = 1;
		if (y >= N) {
			x += (y - N);
			y = N;
		}
		while (0 < y && y <= N && 0 < x && x <= N) {
			if (m[y][x] != 0) {
				m[y][x] = i;
			}
			x++; y--;
		}
	}

	for (int i = 1; i < 2 * N; i++) {
		y = N; x = i;
		if (x >= N) {
			y -= (x - N);
			x = N;
		}
		while (0 < y && y <= N && 0 < x && x <= N) {
			if (m[y][x] != 0) {
				adj[m[y][x]].push_back(i);
			}
			x--; y--;
		}
	}
}

bool dfs(int now) {
	visit[now] = true;
	for (int next : adj[now]) {
		if (right[next] == -1 || !visit[right[next]] && dfs(right[next])) {
			left[now] = next;
			right[next] = now;
			return true;
		}
	}
	return false;
}

void sol2_binarymatching() {
	make_adj();

	int ans = 0;
	for (int i = 1; i < 2 * N; i++) {
		fill(visit.begin(), visit.end(), false);
		if (dfs(i)) ans++;
	}
	printf("%d", ans);
}

int main() {
	init();
//	sol1_backtracking();
	sol2_binarymatching();
	return 0;
}
