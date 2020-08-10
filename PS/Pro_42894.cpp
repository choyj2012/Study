/*
*	https://programmers.co.kr/learn/courses/30/lessons/42894
*	블록게임
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

#define max_square 200
vector<vector<pair<int, int>>> square(max_square + 1);
vector<vector<pair<int, int>>> Empty(max_square + 1);
vector<vector<int>> adj(max_square + 1);
vector<int> in(max_square + 1);
deque<int> Q;

void getEmpty(int sqnum, vector<vector<int>> board) {
	int maxX = -1, maxY = -1, minX = 100, minY = 100;
	for (auto& k : square[sqnum]) {
		maxY = max(maxY, k.first);
		maxX = max(maxX, k.second);
		minY = min(minY, k.first);
		minX = min(minX, k.second);
	}

	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			if (board[y][x] != sqnum)
				Empty[sqnum].push_back({ y, x });
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	int width = board.size();

	for (int i = 0; i < width; i++) {	//조각번호별로 좌표모으기
		for (int j = 0; j < width; j++) {
			if (board[i][j] > 0)
				square[board[i][j]].push_back({ i, j });
		}
	}

	for (int i = 1; i <= max_square; i++) {	//조각번호별로 빈곳 좌표모으기
		if (square[i].empty()) continue;

		getEmpty(i, board);
	}

	for (int i = 1; i <= max_square; i++) {	//자신보다 먼저 제거되어야 하는 조각번호 구하기
		if (Empty[i].empty()) continue;

		bool isStart = true;	//윗쪽에 아무것도 없어서 자기가 먼저 제거가능한지
		for (int a = 0; a <= 1; a++) {	//조각별로 빈곳 2개씩
			
			int Y = Empty[i][a].first;
			int X = Empty[i][a].second;

			for (int y = Y; y >= 0; y--) {
				if (board[y][X] != 0) {
					isStart = false;
					bool isExist = false;
					if (!adj[board[y][X]].empty()) {
						for (auto& k : adj[board[y][X]])
							if (k == i) {
								isExist = true;
								break;
							}
					}
					if (isExist == false) {
						adj[board[y][X]].push_back(i);
						in[i]++;
					}
				}
			}
		}

		if (isStart == true) {	//자신보다 먼저 제거되어야 하는게 없으면
			Q.push_back(i);	//위상정렬 시작지점으로 큐에 넣어둔다.
		}
	}

	//미리 큐에 넣어둔거부터 위상정렬 시작
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop_front();
		answer++;
		for (auto& k : adj[now]) {
			in[k]--;
			if (in[k] == 0) {
				Q.push_back(k);
			}
		}
	}
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N;
	scanf("%d", &N);
	vector<vector<int>> BOARD(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &BOARD[i][j]);
		}
	}

	printf("%d", solution(BOARD));
	return 0;
}