#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int N, K, R;
bool road[MAX][MAX][4];
bool cow[MAX][MAX];
bool check[MAX][MAX];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void checkRoad(int y1, int x1, int y2, int x2) {
	for (int i = 0; i < 4; i++) {
		if (y1 - y2 == dy[i] && x1 - x2 == dx[i])
			road[y2][x2][i] = true;
		if (y2 - y1 == dy[i] && x2 - x1 == dx[i])
			road[y1][x1][i] = true;
	}
}

int bfs(int y, int x) {

	queue<pair<int, int>> Q;
	Q.push({ y, x });
	check[y][x] = true;
	int cnt = 0;
	while (!Q.empty()) {
		auto now = Q.front(); Q.pop();

		if (cow[now.first][now.second]) cnt++;

		for (int i = 0; i < 4; i++) {
			if (road[now.first][now.second][i]) continue;

			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N || check[ny][nx]) continue;

			check[ny][nx] = true;
			Q.push({ ny, nx });
		}
	}
	return cnt;
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> N >> K >> R;

	int y1, x1, y2, x2;
	for (int i = 0; i < R; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		checkRoad(y1, x1, y2, x2);
	}

	vector<pair<int, int>> cowPos(K + 1, pair<int, int>());

	for (int i = 1; i <= K; i++) {
		cin >> y1 >> x1;
		cow[y1][x1] = true;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!check[i][j]) {
				int cnt = bfs(i, j);
				ans += cnt * (K - cnt);
				K -= cnt;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}