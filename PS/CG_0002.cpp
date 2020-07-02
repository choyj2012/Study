#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int Answer = 0;
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++) {

		vector<int> v;
		int n, i, tmp, a = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		int max = 0;
		for (i = 0; i < n; i++) {
			if (max < v[i] + n - i)
				max = v[i] + n - i;
		}

		for (i = 0; i < n; i++) {
			if (max <= v[i] + n) Answer++;
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
		Answer = 0;
	}
	return 0;
}