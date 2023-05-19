#include <iostream>
#include <deque>
using namespace std;

char MAP[11][11];
int H, W;
int check[11][11][11][11];
bool Rclear = false, Bclear = false;

struct pos{
	int y, x;

	pos operator+(const pos& i) {
		pos npos = { y + i.y, x + i.x };
		return npos;
	}

	bool operator==(const pos& i) {
		return y == i.y && x == i.x;
	}
};

pos Red, Blue, Holl;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

pos moveR(pos Rpos, pos Bpos, pos delta);
pos moveB(pos Bpos, pos Rpos, pos delta);

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'B') Blue = { i, j };
			if (MAP[i][j] == 'R') Red = { i, j };
			if (MAP[i][j] == 'O') Holl = { i, j };

			if (MAP[i][j] != '#') MAP[i][j] = '.';
		}
	}

	fill(&check[0][0][0][0], &check[10][10][10][11], -1);
	check[Red.y][Red.x][Blue.y][Blue.x] = 0;
	
	deque<pair<pos, pos>> Q;
	Q.push_back({ Red, Blue });

	while (!Q.empty()) {

		pos Rpos = Q.front().first;
		pos Bpos = Q.front().second;

		Q.pop_front();

		
		for (int i = 0; i < 4; i++) {
			bool Rfirst = false;
			pos nRpos, nBpos;	//next pos
			pos delta = { dy[i], dx[i] };
			
			if (Rpos.x == Bpos.x) {	//xÁÂÇ¥ °°À½
				if (i == 0 && Rpos.y < Bpos.y) Rfirst = true;
				if (i == 2 && Rpos.y > Bpos.y) Rfirst = true;
			}
			if (Rpos.y == Bpos.y) {	//yÁÂÇ¥ °°À½
				if (i == 1 && Rpos.x > Bpos.x) Rfirst = true;
				if (i == 3 && Rpos.x < Bpos.x) Rfirst = true;
			}

			Rclear = Bclear = false;
			if (Rfirst) {
				nRpos = moveR(Rpos, Bpos, delta);
				nBpos = moveB(Bpos, nRpos, delta);
			}
			else {
				nBpos = moveB(Bpos, Bpos, delta);
				nRpos = moveR(Rpos, nBpos, delta);
			}

			if (Bclear) continue;
			if (Rclear) {
				cout << check[Rpos.y][Rpos.x][Bpos.y][Bpos.x] + 1 << "\n";
				return 0;
			}
			if (check[nRpos.y][nRpos.x][nBpos.y][nBpos.x] != -1) continue;

			check[nRpos.y][nRpos.x][nBpos.y][nBpos.x]
				= check[Rpos.y][Rpos.x][Bpos.y][Bpos.x] + 1;

			if (check[nRpos.y][nRpos.x][nBpos.y][nBpos.x] < 10)
				Q.push_back({ nRpos, nBpos });
		}
	}

	cout << -1 << "\n";
	return 0;
}

pos moveR(pos Rpos, pos Bpos, pos delta) {
	pos nowPos = Rpos;
	pos nextPos = Rpos + delta;

	while (1) {
		if (MAP[nextPos.y][nextPos.x] == '#') return nowPos;
		if (nextPos == Bpos) return nowPos;
		if (nextPos == Holl) {
			Rclear = true;
			return { 0, 0 };
		}

		nowPos = nextPos;
		nextPos = nowPos + delta;
	}
}

pos moveB(pos Bpos, pos Rpos, pos delta) {
	pos nowPos = Bpos;
	pos nextPos = Bpos + delta;

	while (1) {
		if (MAP[nextPos.y][nextPos.x] == '#') return nowPos;
		if (nextPos == Rpos) return nowPos;
		if (nextPos == Holl) {
			Bclear = true;
			return nowPos;
		}

		nowPos = nextPos;
		nextPos = nowPos + delta;
	}
}