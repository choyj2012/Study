//https://www.acmicpc.net/problem/1874

#include <stdio.h>
#define N 100010

int n;
int data[N];
int stack[N];
int top = 0;
int idx = 1;
int i, w;
char answer[2 * N];
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}

	for (i = 1; i <= n; i++) {
		stack[++top] = i;
		answer[++w] = '+';

		while (stack[top] == data[idx] && idx <= n) {
			top--;
			idx++;
			answer[++w] = '-';
		}
	}

	if (top != 0) {
		printf("NO");
	}
	else {
		for (i = 1; i <= w; i++) {
			printf("%c\n", answer[i]);
		}
	}
	return 0;
}