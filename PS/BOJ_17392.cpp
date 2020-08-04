#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int area;

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	int t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		area += t + 1;
	}

	if (area > m) {
		printf("0");
		return 0;
	}

	int x = (m - area) / (n + 1);
	int rem = (m - area) % (n + 1);

	long long answer = (x * (x + 1)*(2 * x + 1) / 6) * (n + 1);
	answer += (x + 1)*(x + 1)*rem;

	printf("%d", answer);
}