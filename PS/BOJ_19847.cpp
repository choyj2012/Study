#include <cstdio>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);

	int N, First, prev, now;
	scanf("%d", &N);
	scanf("%d", &First);
	prev = First;
	vector<int> per(First, 1);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &now);
		if (prev <= now) continue;
		
		for (int j = now; j < prev; j++) {
			per[j%now] += per[j];
		}
		prev = now;
	}

	double answer = 0;
	for (int i = 0; i < prev; i++) {
		answer += (double)per[i] * i / First;
	}

	printf("%.10f", answer);
}