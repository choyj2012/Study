#include <stdio.h>

#define N 110

char data[N][N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int y, x;
	int i, j;
	char k;
	scanf("%d %d", &y, &x);
	scanf("%c", &k);
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			scanf("%c ", &data[i][j]);
		}
	}

	for (i = x - 1; i >= 0; i--) {
		for (j = 0; j < y; j++) {
			switch (data[j][i]) {
				case '.':
					printf(".");
					break;
				case 'O':
					printf("O");
					break;
				case '-':
					printf("|");
					break;
				case '|':
					printf("-");
					break;
				case '/':
					printf("\\");
					break;
				case '\\':
					printf("/");
					break;
				case '^':
					printf("<");
					break;
				case '<':
					printf("v");
					break;
				case 'v':
					printf(">");
					break;
				case '>':
					printf("^");
					break;
			}
		}
		printf("\n");
	}
	return 0;
}