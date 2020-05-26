#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		char T[52];
		scanf("%s", T);
		int len = strlen(T);
		int answer = 0, j;
		for (j = 0; j < len; j++) {
			if (T[j] == '(') answer++;
			if (T[j] == ')') answer--;
			
			if (answer < 0)	break;
		}

		if (answer == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}