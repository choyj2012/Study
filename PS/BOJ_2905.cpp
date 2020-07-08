#include <stdio.h>
#include <deque>
using namespace std;

#define N 1000010

int n, x;
int D[N];
long long area;

int main() {
	
	int i;
	scanf("%d %d", &n, &x);
	for (i = 0; i < n; i++) {
		scanf("%d", &D[i]);
		area += D[i];
	}

	deque<pair<int, int>> dq;

	for (i = 0; i < x; i++) {
		while (!dq.empty() && dq.back().second > D[i])
			dq.pop_back();

		dq.push_back({ i, D[i] });
	}

	int nowheight = dq.front().second;
	int cnt = 0;
	int idx = 0;

	for (i = x; i <= n; i++) {
		while (!dq.empty() && dq.back().second > D[i])
			dq.pop_back();

		dq.push_back({ i, D[i] });
		
		if (nowheight != dq.front().second) {
			cnt += (i - idx - 1) / x + 1;
			area -= (long long)(i - idx) * nowheight;
			idx = i;
			nowheight = dq.front().second;
		}

		if (dq.front().first <= i - x) {
			int curidx = dq.front().first;
			dq.pop_front();

			if (nowheight != dq.front().second) {
				cnt += (curidx - idx) / x + 1;
				area -= (long long)(curidx - idx + 1) * nowheight;
				idx = curidx + 1;
				nowheight = dq.front().second;
			}
		}
	}

	printf("%lld\n", area);
	printf("%d", cnt);

	return 0;

}