#include <stdio.h>
#include <cmath>

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int score[][10] = {
		{ 6, 13, 4, 18, 1, 20, 5, 12, 9, 14 },
		{ 10, 15, 2, 17, 3, 19, 7, 16, 8, 11 }
	};

	int T, n, answer;
	int B, T1, T2, D1, D2;
	int i, j, x, y;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		answer = 0;
		scanf("%d %d %d %d %d", &B, &T1, &T2, &D1, &D2);
		scanf("%d", &n);
		for (j = 1; j <= n; j++) {
			scanf("%d %d", &x, &y);
			double angle = atan2(y, x) * 180 / 3.141592 + 9;
			double dis = sqrt(x*x + y * y);
			int flag;
			if (angle > 180) {
				angle = -(360 - angle);
			}
			else if (angle < -180) {
				angle = 360 + angle;
			}

			if (angle > 0) flag = 0;
			else flag = 1;
			angle = abs(angle);
			if (dis < B)
				answer += 50;
			else if (T1 < dis && dis < T2)
				answer += score[flag][(int)angle / 18] * 3;
			else if (D1 < dis && dis < D2)
				answer += score[flag][(int)angle / 18] * 2;
			else if (D2 < dis);
			else
				answer += score[flag][(int)angle / 18];
		}
		printf("Case #%d\n", i);
		printf("%d\n", answer);
	}
}