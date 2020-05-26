#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	scanf("%d", &n);

	vector<int> v;

	for (i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		if (t)
			v.push_back(t);
		else
			v.pop_back();
	}

	vector<int>::iterator it;
	int sum = 0;
	for (it = v.begin(); it != v.end(); it++) {
		sum += *it;
	}
	printf("%d", sum);
}