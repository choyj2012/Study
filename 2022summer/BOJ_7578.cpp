#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAX_DATA 1000001
typedef long long ll;

vector<int> seg(4 * MAX_DATA);
unordered_map<int, int> mapping;
int N;

ll update(int n, int l, int r, int m) {
	
	seg[n]++;

	if (l == r)	return 0LL;

	int mid = (l + r) / 2;
	if (m <= mid) {
		return update(n * 2, l, mid, m) + seg[n * 2 + 1];
	}
	else {
		return update(n * 2 + 1, mid + 1, r, m);
	}
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		mapping[t] = i;
	}

	int m;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		m = mapping[t];

		ans += update(1, 0, N - 1, m);
	}

	printf("%lld", ans);
	return 0;
}