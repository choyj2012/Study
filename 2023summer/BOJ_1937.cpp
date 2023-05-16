#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 510

int ForestSize;
int Forest[MAX][MAX];
bool check[MAX][MAX] = { false, };
int answer[MAX][MAX] = { 0, };

int dfs(int currY, int currX);

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> ForestSize;
	for (int i = 0; i < ForestSize; i++) {
		for (int j = 0; j < ForestSize; j++) {
			cin >> Forest[i][j];
		}
	}

	for (int i = 0; i < ForestSize; i++) {
		for (int j = 0; j < ForestSize; j++) {
			if(!check[i][j]) dfs(i, j);
		}
	}

	int Answer = -1;
	for (int i = 0; i < ForestSize; i++) {
		for (int j = 0; j < ForestSize; j++) {
			Answer = max(Answer, answer[i][j]);
		}
	}
	cout << Answer << "\n";
	return 0 ;
}

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int currY, int currX) {
	check[currY][currX] = true;
	int res = 0;
	for (int i = 0; i < 4; i++) {
		int nextY = currY + dy[i];
		int nextX = currX + dx[i];

		if (0 <= nextY && nextY < ForestSize &&
			0 <= nextX && nextX < ForestSize &&
			Forest[currY][currX] > Forest[nextY][nextX]) {

			if (check[nextY][nextX])
				res = max(res, answer[nextY][nextX]);
			else res = max(res, dfs(nextY, nextX));
		}
	}
	res += 1;
	return answer[currY][currX] = res;
}