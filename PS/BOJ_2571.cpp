#include <stdio.h>
#include <algorithm>
using namespace std;

int n, X, Y;
int map[110][110];
int answer = 0;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &X, &Y);
		
		for (int y = Y + 1; y <= Y + 10; y++) {
			for (int x = X + 1; x <= X + 10; x++) {
				map[y][x] = 1;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] > 0) map[i][j] = map[i - 1][j] + 1;
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] > 0) {
				int h = map[i][j];
				for (int k = j; k <= 100; k++) {
					h = min(h, map[i][k]);
					if (h == 0) break;
					answer = max(answer, h*(k - j + 1));
				}
			}
		}
	}
	printf("%d", answer);
	return 0;
}