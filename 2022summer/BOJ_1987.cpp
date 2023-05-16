#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int m[21][21];
vector<bool> ch;
int ans;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void q(int y, int x, int d) {
	ans = max(ans, d);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || ch[m[ny][nx]]) continue;
		ch[m[ny][nx]] = true;
		q(ny, nx, d + 1);
		ch[m[ny][nx]] = false;
	}
}

int main(){

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &R, &C);
	char t;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &t);
			m[i][j] = t - 65;
		}
	}
	
	ch.resize(26, false);
	ch[m[0][0]] = true;
	q(0, 0, 1);

	printf("%d", ans);
	return 0;
}