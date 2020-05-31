//https://www.acmicpc.net/problem/2879

#include <stdio.h>
#include <math.h>
#define N 1010

int be[N];	//현재befor
int af[N];	//목표after
int n, i;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &be[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &af[i]);
	}
	
	int gap = 0;
	int sum = 0;
	int now = 0;
	
	for (i = 1; i <= n; i++) {	//iii)부호 바뀌는 경우
		gap = af[i] - be[i];
		if (now * gap < 0) {
			sum += abs(now);
			now = gap;
			continue;
		}

		if (abs(now) < abs(gap)) {	//i)같은구간에서 증가하는경우
			now = gap;
		}
		else if (abs(now) > abs(gap)) {	//ii)같은구간에서 감소하는경우
			sum += (abs(now) - abs(gap));
			now = gap;
		}
	}
	sum += abs(now);	//vi)for문끝나고 그리던 막대 끝내주기
	printf("%d", sum);
	return 0;
}