#include <iostream>
#include <deque>
#include <string>
using namespace std;

int H, W;
int MAP[110][110];
int check[5][110][110];
int answer[5][110][110];
//µ¿1 ¼­2 ³²3 ºÏ4

int turn[5][5] = {
	{ 0, },
	{ 0, 0, 2, 1, 1},
	{ 0, 2, 0, 1, 1},
	{ 0, 1, 1, 0, 2},
	{ 0, 1, 1, 2, 0}
};

struct State{
	int x;
	int y;
	int dir;

	bool operator==(const State& i) {
		return i.x == x && i.y == y && i.dir == dir;
	}
};

State Start, End;

int dy[] = { 0, 0, 0, 1, -1 };
int dx[] = { 0, 1, -1, 0, 0 };

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	fill(&check[0][0][0], &check[5 - 1][110 - 1][110], false);
	fill(&answer[0][0][0], &answer[5 - 1][110 - 1][110], -1);

	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> MAP[i][j];
		}
	}

	cin >> Start.y >> Start.x >> Start.dir;
	cin >> End.y >> End.x >> End.dir;


	deque<State> Q;

	check[Start.dir][Start.y][Start.x] = true;
	answer[Start.dir][Start.y][Start.x] = 0;
	Q.push_back(Start);

	while (!Q.empty()) {

		if (Q.front() == End) break;

		int nx = Q.front().x;
		int ny = Q.front().y;
		int ndir = Q.front().dir;
		Q.pop_front();

		int tox = nx;
		int toy = ny;
		for(int i=0; i<3; i++) {
			tox += dx[ndir];
			toy += dy[ndir];

			if (tox <= 0 || tox > W || toy <= 0 || toy > H ||
				MAP[toy][tox] == 1) break;

			if (check[ndir][toy][tox]) continue;

			check[ndir][toy][tox] = true;
			answer[ndir][toy][tox] = answer[ndir][ny][nx] + 1;
			State tmp = { tox, toy, ndir };
			Q.push_back(tmp);
		}

		for (int i = 1; i <= 4; i++) {
			if (check[i][ny][nx] == false) {
				answer[i][ny][nx] = answer[ndir][ny][nx] + turn[ndir][i];
				check[i][ny][nx] = true;

				State tmp = { nx, ny, i };
				Q.push_back(tmp);
			}
		}
	}

	cout << answer[End.dir][End.y][End.x] << "\n";
	return 0;
}