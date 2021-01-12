#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> P;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

struct compare {
	bool operator()(P a, P b) {
		return get<2>(a) > get<2>(b);
	}
};

int R, C;
vector<vector<char>> map;
vector<vector<int>> day;	//얼음이 녹는 날짜 전처리
vector<vector<int>> check;
pair<int, int> L[2];

void init() {
	scanf("%d %d", &R, &C);

	priority_queue<P, vector<P>, compare> Q;	//tuple<int, int, int> -> y좌표, x좌표, 얼음이 녹는날
	map.resize(R, vector<char>(C));
	day.resize(R, vector<int>(C));
	check.resize(R, vector<int>(C, 0));

	int k = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);

			switch (map[i][j]) {
			case 'L':
				L[k++] = { i, j };	//L[0] 시작 백조위치, L[1] 도착 백조위치
			case '.':
				Q.push({ i, j, 0 });
				check[i][j] = -1;
			}
		}
	}

	while (!Q.empty()) {	//얼음 녹는날짜 계산

		int nowy = get<0>(Q.top());
		int nowx = get<1>(Q.top());
		int nowd = get<2>(Q.top());
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if (ny >= 0 && ny < R && nx >= 0 && nx < C && check[ny][nx] == 0) {
				check[ny][nx] = -1;

				day[ny][nx] = nowd + 1;
				Q.push({ ny, nx, day[ny][nx] });
			}
		}
	}

	/*for (int i = 0; i < R; i++) {	//얼음 녹는날짜 계산 테스트
		for (int j = 0; j < C; j++) {
			printf("%d", day[i][j]);
		}
		printf("\n");
	}*/
}

bool sol(int d) {

	deque<pair<int, int>> Q;
	Q.push_front({ L[0].first, L[0].second });
	check[L[0].first][L[0].second] = d;

	/*
	얼음이 녹는날짜를 계산해놓은 맵에서 d이하의 칸만 이동가능
	*/
	while (!Q.empty()) {
		auto now = Q.back();
		if (L[1] == now) return true;
		Q.pop_back();

		int nowy = now.first;
		int nowx = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if (ny >= 0 && ny < R && nx >= 0 && nx < C && check[ny][nx] != d && day[ny][nx] <= d) {
				check[ny][nx] = d;
				Q.push_front({ ny, nx });
			}
		}
	}

	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	
	init();

	/*
	d일에 백조가 만나지 못한다면 d-1에도 만나지 못한다 -> 이분탐색
	*/

	int maxd = (R + C) / 2;
	int mind = 1;
	while (1) {
		if (mind == maxd) break;

		int mm = (mind + maxd) / 2;
		if (sol(mm))	//d일일때 만날 수 있는가
			maxd = mm;
		else
			mind = mm + 1;

	}

	printf("%d", mind);
	return 0;
}