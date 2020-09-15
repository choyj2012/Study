#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

vector<vector<char>> bfs(int y, int x, vector<vector<char>> board);
void print(vector<vector<char>> b);

int answer = 0;
bool changed;

int main() {
	freopen("input.txt", "r", stdin);

	vector<vector<char>> board(12, vector<char>(6));


	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%c ", &board[i][j]);
		}
	}

	bool end = false;
	while (1) {

		changed = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					board = bfs(i, j, board);
				}
			}
		}

		if (changed) answer++;
		else break;
		print(board);

		for (int j = 0; j < 6; j++) {
			int re = 11;
			for (int i = 11; i >= 0; i--) {
				if (board[i][j] != '.') {
					if (i != re) {
						board[re][j] = board[i][j];
						board[i][j] = '.';
					}
					re--;
				}
			}
		}
		print(board);
	}

	printf("%d\n", answer);
	return 0;
}

vector<vector<char>> bfs(int y, int x, vector<vector<char>> board) {

	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	int cnt = 0;
	vector<vector<bool>> check(12, vector<bool>(6, false));
	vector<pair<int, int>> del;
	deque<pair<int, int>> Q;
	Q.push_back({ y,x });
	check[y][x] = true;

	while (!Q.empty()) {

		int ny = Q.back().first;
		int nx = Q.back().second;
		Q.pop_back();
		del.push_back({ ny, nx });
		cnt++;

		for (int i = 0; i < 4; i++) {
			if (ny + dy[i] >= 0 && ny + dy[i] < 12 && nx + dx[i] >= 0 && nx + dx[i] < 6 &&
				board[ny][nx] == board[ny + dy[i]][nx + dx[i]] && !check[ny + dy[i]][nx + dx[i]]) {

				Q.push_front({ ny + dy[i], nx + dx[i] });
				check[ny + dy[i]][nx + dx[i]] = true;
			}
		}
	}

	if (cnt >= 4) {
		changed = true;
		for (auto k : del) {
			board[k.first][k.second] = '.';
		}
	}

	return board;
}

void print(vector<vector<char>> b) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}