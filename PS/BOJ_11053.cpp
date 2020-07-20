#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, t;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if (v.empty()) {
			v.push_back(t);
			continue;
		}
		if (v.back() < t)
			v.push_back(t);
		else if (v.back() == t) continue;
		else {
			auto it = lower_bound(v.begin(), v.end(), t);
			*it = t;
		}
	}

	printf("%d", v.size());
	return 0;
}