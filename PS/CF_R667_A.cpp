#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

	int T, n, m;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		int answer = abs(m - n) / 10;
		if (abs(m - n) % 10) answer++;

		printf("%d\n", answer);
	}
	return 0;
}