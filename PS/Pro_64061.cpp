#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<vector<int>> stack(board.size(), vector<int>());
	vector<int> basket;
	for (int i = board.size() - 1; i >= 0; i--) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] > 0)
				stack[j].push_back(board[i][j]);
		}
	}

	for (int i = 0; i < moves.size(); i++) {
		if (!stack[moves[i] - 1].empty()) {

			int now = stack[moves[i] - 1].back();

			if (!basket.empty() && basket.back() == now) {
				basket.pop_back();
				answer += 2;
			}
			else
				basket.push_back(now);

			stack[moves[i] - 1].pop_back();
		}

	}

	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(N));
	vector<int> moves;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	int t;
	for (int i = 0; i < M; i++) {
		cin >> t;
		moves.push_back(t);
	}

	cout << solution(board, moves) << endl;
	return 0;
}