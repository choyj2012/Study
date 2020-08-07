#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100010

int T, n, k;


bool compare(int a, int b) {
	return a > b;
}
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		vector<int> cnt(MAX_SIZE, 0);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &k);
			cnt[k]++;
		}

		sort(cnt.begin(), cnt.end(), compare);

		int aa = cnt[0];
		int j = 1;
		while (1) {
			if (aa != cnt[j]) break;
			j++;
		}

		int ans = j - 1 + (n - (j * cnt[0])) / (cnt[0] - 1);
		printf("%d\n", ans);
	}
	return 0;
}