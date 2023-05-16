#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
int N, M, K;
int m[MAX][MAX];
int maxD = -1;
int minD = 987654321;

bool test(int D);
int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
			maxD = max(maxD, m[i][j]);
			minD = min(minD, m[i][j]);
		}
	}

	int ans = -1;
	while (minD <= maxD) {
		int mid = (minD + maxD) / 2;
		if (test(mid)) {
			maxD = mid - 1;
			ans = mid;
		}
		else {
			minD = mid + 1;
		}
	}
	
	printf("%d", ans);
}

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool test(int D) {
	
	vector<vector<bool>> check(N, vector<bool>(M, false));
	queue<pair<int, int>> q;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (m[i][0] <= D) {
			q.push({ i, 0 });
			check[i][0] = true;
		}
		if (m[i][M - 1] <= D) {
			q.push({ i, M - 1 });
			check[i][M - 1] = true;
		}
	}
	for (int i = 1; i < M - 1; i++) {
		if (m[0][i] <= D) {
			q.push({ 0, i });
			check[0][i] = true;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;

		if (cnt >= K) return true;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx<0 || nx >= M ||
				check[ny][nx] || m[ny][nx]>D) continue;

			q.push({ ny, nx });
			check[ny][nx] = true;
		}

	}

	return false;
}