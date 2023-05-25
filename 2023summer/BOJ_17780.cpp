#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

const int MAP_MAX = 15;
const int RED = 1;
const int BLUE = 2;

const int RIGHT = 1;
const int LEFT = 2;
const int UP = 3;
const int DOWN = 4;

int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };
int chdir[] = { 0, 2, 1, 4, 3 };

int MAP[MAP_MAX][MAP_MAX];
int N, K;
vector<array<int, 3>> currPos(15);
vector<int> mapState[MAP_MAX][MAP_MAX];

void init() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> currPos[i][0] >> currPos[i][1] >> currPos[i][2];
		mapState[currPos[i][0]][currPos[i][1]].push_back(i);
	}
}

void move(int cy, int cx, int ny, int nx, bool rv) {
	for (int num : mapState[cy][cx])
		currPos[num] = { ny, nx, currPos[num][2] };
	
	if (rv) {
		mapState[ny][nx].insert(mapState[ny][nx].end(),
			mapState[cy][cx].rbegin(), mapState[cy][cx].rend()
		);
	}
	else {
		mapState[ny][nx].insert(mapState[ny][nx].end(),
			mapState[cy][cx].begin(), mapState[cy][cx].end()
		);
	}
	mapState[cy][cx] = vector<int>();
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	init();
	int turn = 0;
	while (turn <= 1000) {
		turn++;
		for (int i = 1; i <= K; i++) {
			int cy = currPos[i][0];
			int cx = currPos[i][1];
			int& dir = currPos[i][2];

			//현재 움직이려는 말이 맨 아래 있지 않은 경우
			if (mapState[cy][cx].front() != i) continue;

			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			//맵 범위 밖인 경우 or 파란색인 경우
			if (ny == 0 || ny > N || nx == 0 || nx > N || MAP[ny][nx] == BLUE) {
				dir = chdir[dir];
				ny = cy + dy[dir];
				nx = cx + dx[dir];

			}
			
			//다시 이동하려는 칸이 맵 밖 or 파란색
			if (ny == 0 || ny > N || nx == 0 || nx > N || MAP[ny][nx] == BLUE) continue;

			//빨간색인 경우
			else if (MAP[ny][nx] == RED) {
				move(cy, cx, ny, nx, true);
			}

			//흰색인 경우
			else {
				move(cy, cx, ny, nx, false);
			}

			if (mapState[ny][nx].size() >= 4) {
				cout << turn << "\n";
				return 0;
			}
		}
	}
	cout << -1 << "\n";
	return 0;
}