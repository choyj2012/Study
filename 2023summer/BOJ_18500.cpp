#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX = 101;

int H, W, N;
char MAP[MAX][MAX];
vector<int> shoot;

void init() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> N;

	for (int i = 0, t; i < N; i++) {
		cin >> t;
		shoot.push_back(t);
	}
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> bfs(int y, int x, vector<vector<bool>>& check, bool replace) {

	vector<pair<int, int>> cluster;
	deque<pair<int, int>> Q;
	Q.push_back({ y, x });
	check[y][x] = true;

	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		cluster.push_back({ cy, cx });
		if (replace) MAP[cy][cx] = '.';
		Q.pop_front();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W ||
				check[ny][nx] || MAP[ny][nx] == '.')
				continue;

			check[ny][nx] = true;
			Q.push_back({ ny, nx });
		}
	}

	return cluster;
}

void crack(int h, bool LtoR) {
	if (LtoR) {
		for (int t = 0; t < W; t++) {
			if (MAP[h][t] == 'x') {
				MAP[h][t] = '.';
				return;
			}
		}
	}
	else {
		for (int t = W - 1; t >= 0; t--) {
			if (MAP[h][t] == 'x') {
				MAP[h][t] = '.';
				return;
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	cin >> H >> W;
	
	init();

	bool LtoR = true;
	for (int h : shoot) {

		crack(H - h, LtoR);
		LtoR = !LtoR;

		vector<vector<bool>> check(H, vector<bool>(W, false));
		for (int i = 0; i < W; i++) {
			if(MAP[H-1][i] == 'x' && !check[H-1][i])	//1층부터 bfs : 바닥에 붙어있는부분
				bfs(H - 1, i, check, false);
		}

		vector<pair<int, int>> cluster;	// 클러스터 여러개가 동시에 떨어지는 경우 x
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (MAP[y][x] == 'x' && !check[y][x])	//위쪽부터 bfs : 공중에 떠있는부분
					cluster = bfs(y, x, check, true);
			}
		}

		sort(cluster.begin(), cluster.end(), [](const pair<int, int>& i, const pair<int, int>& j) {
			if (i.second == j.second) return i.first > j.first;
			else return i.second < j.second;
		});

		int minDropH = 999;
		for (auto mineral : cluster) {
			int nowx = mineral.second;

			int dropH = 0;
			for (int y = mineral.first + 1; y < H; y++) {
				if (MAP[y][nowx] == 'x') break;
				dropH++;
			}
			minDropH = min(minDropH, dropH);
		}

		for (auto& mineral : cluster) {
			mineral.first += minDropH;
			MAP[mineral.first][mineral.second] = 'x';
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}
	return 0;
}