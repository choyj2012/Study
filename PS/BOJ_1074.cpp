#include <stdio.h>

int N, r, c, n = 1;
int answer;

void find(int x1, int x2, int y1, int y2) {

	if (x1 == x2 && y1 == y2) return;

	int xm = (x1 + x2) / 2;
	int ym = (y1 + y2) / 2;

	if (r <= ym && c <= xm) {	//1
		find(x1, xm, y1, ym);
	}
	else if (r <= ym && c > xm) {	//2
		answer = answer + (x2 - x1 + 1)*(x2 - x1 + 1) / 4;
		find(xm + 1, x2, y1, ym);
	}
	else if (r > ym && c <= xm) {	//3
		answer = answer + (x2 - x1 + 1)*(x2 - x1 + 1) / 4 * 2;
		find(x1, xm, ym + 1, y2);
	}
	else if (r > ym && c > xm) {	//4
		answer = answer + (x2 - x1 + 1)*(x2 - x1 + 1) / 4 * 3;
		find(xm + 1, x2, ym + 1, y2);
	}

}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i;

	scanf("%d %d %d", &N, &r, &c);

	for (i = 1; i <= N; i++) n *= 2;
	
	find(0, n - 1, 0, n - 1);

	printf("%d", answer);
}