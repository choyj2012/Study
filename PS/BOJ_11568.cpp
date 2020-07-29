#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> lis;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		
		if (lis.empty() || lis.back() < t) {
			lis.push_back(t);
		}
		else if (lis.back() > t) {
			auto it = lower_bound(lis.begin(), lis.end(), t);
			*it = t;
		}
	}

	printf("%d", lis.size());
	return 0;
}