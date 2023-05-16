#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1010
#define INF 2000000

int N, M;
int mmap[MAX][MAX];
int dist[MAX][MAX][2];

int bfs();

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &mmap[i][j]);
		}
	}

	printf("%d", bfs());

	

	return 0;
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int T = q.front().second;
		q.pop();

		if (y == N-1 && x == M-1) return dist[y][x][T];
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < N && 0 <= nx && nx < M && !dist[ny][nx][T]) {
				if (mmap[ny][nx] == 0) {
					dist[ny][nx][T] = dist[y][x][T] + 1;
					q.push({ {ny,nx}, T });
				}
				if (mmap[ny][nx] == 1 && T==0) {
					dist[ny][nx][1] = dist[y][x][T] + 1;
					q.push({ {ny,nx}, 1 });
				}
			}
		}
	}

	return -1;
}