#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		if (v[n - 1] >= v[0] + v[1]) {
			printf("1 2 %d\n", n);
		}
		else
			printf("-1\n");
	}
	return 0;
}