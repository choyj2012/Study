#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n, k, answer = 0;
	int i, j, tmp;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		answer = 0;
		scanf("%d %d", &n, &k);
		vector<int> v;

		for (j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		vector<int>::reverse_iterator it = v.rbegin();
		for (j = 1; j <= k; j++) {
			answer += *it;
			it++;
		}

		printf("Case #%d\n", i);
		printf("%d\n", answer);
	}
	return 0;
}