#include <stdio.h>
#define N 10

int n, i, sum = 0;
int x, y;
int X[N];
int Y[N];
struct pos {
	int x;
	int y;
}Data[N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		X[x]++;
		Y[y]++;
		Data[i].x = x;
		Data[i].y = y;
	}
	
	for (i = 1; i <= n; i++) {
		sum += (X[Data[i].x] - 1) * (Y[Data[i].y-1]);
	}

	printf("%d", sum);
}