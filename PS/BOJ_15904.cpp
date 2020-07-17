#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char UCPC[] = "UCPC";
	char t;
	int idx = 0;
	while (1) {
		scanf("%c", &t);

		if (t == '\n') break;

		if (t == UCPC[idx]) idx++;
	}

	if (idx == 4) printf("I love UCPC");
	else printf("I hate UCPC");

	return 0;
}