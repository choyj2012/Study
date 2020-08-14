#include <cstdio>

int main() {

	int N, M, y, x;
	scanf("%d %d %d %d", &N, &M, &y, &x);

	for (int i = y; i <= N; i++) {
		printf("%d %d\n", i, x);
	}

	for (int i = y - 1; i >= 1; i--) {
		printf("%d %d\n", i, x);
	}

	bool flag = true;
	for (int i = 1; i <= M; i++) {
		if (i == x) continue;
		if (flag) {
			for (int j = 1; j <= N; j++) {
				printf("%d %d\n", j, i);
			}
			flag = !flag;
		}
		else {
			for (int j = N; j >= 1; j--) {
				printf("%d %d\n", j, i);
			}
			flag = !flag;
		}
	}

	return 0;
}