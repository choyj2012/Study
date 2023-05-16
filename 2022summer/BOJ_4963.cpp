#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void bfs(int y, int x, int h, int w, vector<vector<int>>& m) {

	queue<pair<int, int>> q;
	q.push({ y, x });
	m[y][x] = 0;

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny<0 || ny>h || nx<0 || nx>w || m[ny][nx] == 0) continue;

			q.push({ ny,nx });
			m[ny][nx] = 0;
		}
	}
}

void solve(int w, int h) {
	
	vector<vector<int>> m(h + 1, vector<int>(w + 1));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == 1) {
				bfs(i, j, h, w, m);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}

int main() {

	freopen("input.txt", "r", stdin);

	while (1) {
		int w, h;
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) break;
		
		solve(w, h);
	}
}