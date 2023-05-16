#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N = 10;
vector<vector<char>> M(10, vector<char>(10));
int on_init;
int on_cnt;
int flip_cnt;
int ans = 999;
int dy[] = { 0, 1, 0, -1, 0 };
int dx[] = { 1, 0, -1, 0, 0 };

void init();
void test(int bit, vector<vector<char>> m);
void flip(int y, int x, vector<vector<char>>& m);

int main() {

	freopen("input.txt", "r", stdin);
	
	init();
	for (int i = 0; i < 1024; i++) {
		flip_cnt = 0;
		on_cnt = on_init;
		test(i, M);
		if(on_cnt==0) 
			ans = min(ans, flip_cnt);
	}
	if (ans == 999) ans = -1;
	printf("%d", ans);
	return 0;
}

void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf(" %c", &M[i][j]);
			if (M[i][j] == 'O') on_init++;
		}
	}
}

void test(int bit, vector<vector<char>> m) {

	for (int i = 9; i >= 0; i--) {
		if (bit & 1) flip(0, i, m);
		bit = (bit >> 1);
	}
	int y = 0;
	int x = 9;
	while (1) {
		
		x++;
		if (x == N) {
			x = 0;
			y++;
		}
		if (y==N || on_cnt == 0) return;

		if (m[y - 1][x] == 'O') 
			flip(y, x, m);
	}
}

void flip(int y, int x, vector<vector<char>>& m) {
	flip_cnt++;
	for (int i = 0; i < 5; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (m[ny][nx] == '#') {
			m[ny][nx] = 'O';
			on_cnt++;
		}
		else {
			m[ny][nx] = '#';
			on_cnt--;
		}
	}
}