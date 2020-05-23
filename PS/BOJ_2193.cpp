//https://www.acmicpc.net/problem/2193

#include <stdio.h>

long long int answer;
int n;

void pibo(long long int prev, long long int now, int cnt) {
	if (cnt == n)answer = now;
	else
		pibo(now, prev + now, cnt + 1);
}
int main() {
	
	scanf("%d", &n);
	pibo(0LL, 1LL, 1);
	printf("%lld", answer);
	return 0;
}