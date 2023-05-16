#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
int N;
int m[MAX][MAX];
bool visit[MAX][MAX];
int mi = 201, ma = -1;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool test(int gap);
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &m[i][j]);
			if (m[i][j] < mi) mi = m[i][j];
			if (m[i][j] > ma) ma = m[i][j];
		}
	}

	int lo = (int)abs(m[1][1] - m[N][N]);
	int hi = ma - mi;
	while (lo < hi) {
		int mid = (hi + lo) / 2;

		if (test(mid)) hi = mid;
		else lo = mid + 1;
	}

	printf("%d", lo);
	return 0;
}

bool test(int gap) {

	for (int i = mi; i <= ma - gap; i++) {
		
		if (!(i <= m[1][1] && m[1][1] <= i + gap)) continue;

		memset(visit, false, sizeof(visit));
		queue<pair<int, int>> q;
		q.push({ 1,1 });
		visit[1][1] = true;

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == N && x == N) return true;
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny<1 || ny>N || nx<1 || nx>N || visit[ny][nx]) continue;
				
				if (i <= m[ny][nx] && m[ny][nx] <= i + gap) {
					q.push({ ny, nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
	return false;
}

/*
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
#define INF 9876
int N;
int m[MAX][MAX];
vector<vector<pair<int, int>>> range;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	range.assign(N + 1, vector<pair<int, int>>(N + 1, { -INF, INF }));

	if (m[1][1] <= m[N][N]) range[1][1] = { m[1][1], m[N][N] };
	else range[1][1] = { m[N][N], m[1][1] };

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int l = range[y][x].first;
		int h = range[y][x].second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<1 || ny>N || nx<1 || nx>N) continue;
			
			int ngap = range[ny][nx].second - range[ny][nx].first;
			int nnum = m[ny][nx];

			int gap;
			int nl, nh;
			if (l <= nnum && nnum <= h) {
				gap = h - l;
				nl = l;	nh = h;
			}
			else if (nnum < l) {
				gap = h - nnum;
				nl = nnum; nh = h;
			}
			else if (h < nnum) {
				gap = nnum - l;
				nl = l; nh = nnum;
			}

			if (gap < ngap) {
				range[ny][nx] = { nl, nh };
				q.push({ ny, nx });
			}
		}
	}

	printf("%d", range[N][N].second - range[N][N].first);
	return 0;
}

반례
5
10 5  15 99 99
6  99 10 99 99
16 10 10 7  18
99 99 7  99 10
99 99 18 10 10

[3][3]에서 (6,16) or (5,15) 둘다 gap은 10이지만,
뭐가 들어가냐에 따라 결과가 달라짐
*/