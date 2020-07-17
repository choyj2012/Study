#include <stdio.h>

int answer[301];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int d[301];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	
	answer[1] = d[1];
	answer[2] = d[1] + d[2];

	for (int i = 2; i <= n; i++) {
		answer[i] = (d[i] + answer[i - 2]) > (d[i] + d[i - 1] + answer[i - 3]) 
			? (d[i] + answer[i - 2]) : d[i] + d[i - 1] + answer[i - 3];
	}

	printf("%d", answer[n]);
	return 0;
}