#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, t;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back({ t, i });
	}

	sort(v.begin(), v.end());
	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer = max(answer, v[i].second - i);
	}

	printf("%d", answer + 1);
	return 0;
}