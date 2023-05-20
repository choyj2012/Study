#include <iostream>
#include <queue>
using namespace std;

int H, W;
int MAP[510][510];
bool check[510][510];
int answer[510][510];

struct pos {
	int y, x, h;

	pos(int _y, int _x, int _h) : y(_y), x(_x), h(_h) {}
};

struct cmp {
	bool operator()(const pos& i, const pos& j) {
		return i.h < j.h;
	}
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> MAP[i][j];
		}
	}

	
	priority_queue<pos, vector<pos>, cmp> Q;
	Q.push(pos(0, 0, MAP[0][0]));
	answer[0][0] = 1;

	while (!Q.empty()) {
		pos now = Q.top();
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nextY = now.y + dy[i];
			int nextX = now.x + dx[i];
			int nextH = MAP[nextY][nextX];

			if (nextY < 0 || nextY >= H || nextX < 0 || nextX >= W) continue;

			//현재 위치 값 구하기
			if (now.h < nextH) answer[now.y][now.x] += answer[nextY][nextX];
			
			//주변 위치 큐에 넣기
			if (check[nextY][nextX] || now.h <= nextH) continue;
			
			check[nextY][nextX] = true;
			Q.push(pos(nextY, nextX, MAP[nextY][nextX]));
		}
	}

	cout << answer[H - 1][W - 1] << "\n";
	return 0;
}