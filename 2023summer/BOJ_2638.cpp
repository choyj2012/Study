#include <iostream>
#include <deque>
#include <array>
using namespace std;

#define MAX 101

int H, W;
int cheese[MAX][MAX];
bool check[MAX][MAX];
int airCnt[MAX][MAX];
int cheeseCnt = 0;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) cheeseCnt++;
		}
	}

	deque<array<int, 2>> Q;
	deque<array<int, 2>> nextQ;
	nextQ.push_back({ 0, 0 });

	int ans = 0;
	while (cheeseCnt) {
		Q = nextQ;
		nextQ.clear();
		ans++;
		while (!Q.empty()) {
			auto now = Q.front(); Q.pop_front();

			for (int i = 0; i < 4; i++) {
				int ny = now[0] + dy[i];
				int nx = now[1] + dx[i];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W || check[ny][nx])
					continue;

				if (cheese[ny][nx] == 0) {
					Q.push_back({ ny, nx });
					check[ny][nx] = true;
				}
				else if (cheese[ny][nx] == 1) {
					airCnt[ny][nx]++;
					if (airCnt[ny][nx] >= 2) {
						nextQ.push_back({ ny,nx });
						cheeseCnt--;
						check[ny][nx] = true;
					}
				}
			}
		}
	}

	cout << ans << "\n";
	return 0;
}