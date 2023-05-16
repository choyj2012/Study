#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1010
int sqH, sqW;
int sqMap[MAX][MAX];
int sqSizeDp[MAX][MAX];
int Answer;
int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> sqH >> sqW;
	char tmp;
	for (int i = 0; i < sqH; i++) {
		for (int j = 0; j < sqW; j++) {
			cin >> tmp;
			sqMap[i][j] = tmp - '0';
		}
	}

	for (int i = 0; i < sqH; i++) {
		for (int j = 0; j < sqW; j++) {
			if (i == 0 || j == 0 || sqMap[i][j] == 0) {
				sqSizeDp[i][j] = sqMap[i][j];
				Answer = max(Answer, sqSizeDp[i][j]);
				continue;
			}

			int minWidth = min(sqSizeDp[i - 1][j], sqSizeDp[i][j - 1]);

			if (sqMap[i - minWidth][j - minWidth] == 1) 
				sqSizeDp[i][j] = minWidth + 1;
			else sqSizeDp[i][j] = max(1, minWidth);

			Answer = max(Answer, sqSizeDp[i][j]);
		}
	}

	cout << Answer * Answer << "\n";
	return 0;
}

/*
Case#1
input
1 1
1

output
1
*/