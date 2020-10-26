#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 1 << 3;
vector<int> seg(SIZE * 2);
vector<int> sum(100010);

void init() {
	for (int i = SIZE - 1; i > 0; i--) {
		seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
}

int query(int l, int r) {

	int ret = 1e9;
	l += SIZE - 1;
	r += SIZE - 1;

	while (l <= r) {
		if (l % 2 == 1) ret = min(ret, seg[l++]);
		if (r % 2 == 0) ret = min(ret, seg[r--]);
		l /= 2;
		r /= 2;
	}
	return ret;
	
}

int main() {

	freopen("input.txt", "r", stdin);
	string str;
	int ans = 0;
	int Q;
	cin >> str;

	for (int i = 1; i <= str.size(); i++) {
		 int t = (str[i - 1] == '(') ? 1 : -1;
		 seg[SIZE + i - 1] = sum[i] = sum[i - 1] + t;
	}

	init();


	scanf("%d", &Q);
	int l, r;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &l, &r);
		int ret = query(l, r);
		if (sum[r] - sum[l - 1] == 0 && ret - sum[l - 1] >= 0) ans++;
	}

	printf("%d", ans);
	return 0;
}