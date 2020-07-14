#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<long long> v;
	int n, m;
	long long sum = 0;
	int i, t;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &t);
		v.push_back(t);
		sum += t;
	}

	for (i = 1; i <= m; i++) {
		sort(v.begin(), v.end());
		v[0] += v[1];
		v[1] = v[0];
		sum += v[0];
	}

	printf("%lld", sum);
	return 0;
}