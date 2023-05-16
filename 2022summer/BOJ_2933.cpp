#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 101
int R, C, N;
char m[MAX][MAX];

void shoot(int floor, int side);
void bfs(int sy, int sx, vector<vector<bool>> &ch);
void drop(int sy, int sx);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &m[i][j]);
		}
	}

	scanf("%d", &N);
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);

		shoot(R-t, i % 2);

		//for (int I = 0; I < R; I++) {
		//	for (int J = 0; J < C; J++) printf("%c", m[I][J]);
		//	printf("\n");
		//}
		//printf("\n");
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) printf("%c", m[i][j]);
		printf("\n");
	}
	return 0;
}

void shoot(int floor, int side) {
	//side==1 l->r
	if (side == 0) {
		for(int i=0; i<C; i++)
			if (m[floor][i] == 'x') {
				m[floor][i] = '.';
				break;
			}
	}
	//side==0 r->l
	if (side == 1) {
		for (int i = C - 1; i >= 0; i--) {
			if (m[floor][i] == 'x') {
				m[floor][i] = '.';
				break;
			}
		}
	}

	vector<vector<bool>> check(R, vector<bool>(C, false));
	for (int i = R - 1; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			if (check[i][j] == false && m[i][j] == 'x') {
				if (i < R - 1) { //공중에 있음
					drop(i, j);
					return;
				}
				else bfs(i, j, check);
			}

		}
	}

}

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
void bfs(int sy, int sx, vector<vector<bool>> &ch) {

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	ch[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C ||
				ch[ny][nx] || m[ny][nx] == '.') continue;

			q.push({ ny, nx });
			ch[ny][nx] = true;
		}
	}
}

bool cmp(const pair<int, int> &i, const pair<int, int> &j) {
	if (i.second == j.second)
		return i.first > j.first;
	return i.second < j.second;
}
void drop(int sy, int sx) {
	//떨어뜨릴 미네랄 집합 구하기
	vector<pair<int, int>> cluster; //떨어뜨릴 미네랄 좌표집합
	queue<pair<int, int>> q;
	cluster.push_back({ sy, sx });
	q.push({ sy, sx });
	m[sy][sx] = '.';

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C ||
				m[ny][nx] == '.') continue;

			cluster.push_back({ ny, nx });
			q.push({ ny, nx });
			m[ny][nx] = '.';
		}
	}

	//미네랄 좌표중에 각 열에서 가장 아래 있는거에
	//대해서만 떨어뜨릴 높이 계산
	sort(cluster.begin(), cluster.end(), cmp);

	//떨어뜨릴 높이 계산(mcnt)
	int mcnt = 999;
	int row = -1;
	for (auto p : cluster) {
		if (row == p.second) continue;
		row = p.second;
		int cnt = 0;
		for (int i = p.first + 1; i < R; i++) {
			if (m[i][row] == '.') cnt++;
			else break;
		}
		mcnt = (mcnt > cnt) ? cnt : mcnt;
	}

	//mcnt만큼 떨어뜨림
	for (auto p : cluster) {
		m[p.first + mcnt][p.second] = 'x';
	}
}