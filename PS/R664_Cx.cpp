#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 2<<11-1

int n, m;
int I[210];
int J[210];

bool compare(int a, int b) {
	return a > b;
}
int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &I[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &J[i]);
	}

	sort(I, I + n, compare);
	sort(J, J + m, compare);
	int ctmp;
	int c = 0;
	
	for (int i = 0; i < n; i++) {
		int min = MAX;
		for (int j = 0; j < m; j++) {

			ctmp = (I[i] & J[j]);

			if ((c | min) > (c | ctmp)) {
				min = ctmp;
			}
		}

		c = (c | min);
	}

	printf("%d", c);
	return 0;
}