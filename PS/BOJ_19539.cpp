#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d;
int n, t;
int sum = 0;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		sum += t;
		d.push_back(t);
	}
	if (sum % 3 != 0) {
		printf("NO");
		return 0;
	}
	
	sort(d.begin(), d.end());
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < n; i++) {

		while (cnt1 > 0 && d[i] - 2 >= 0) {
			d[i] -= 2;
			cnt1--;
		}
		while (cnt2 > 0 && d[i] - 1 >= 0) {
			d[i] -= 1;
			cnt2--;
		}
		d[i] %= 3;
		if (d[i] == 1) cnt1++;
		if (d[i] == 2) cnt2++;

	}

	if (cnt1 == 0 && cnt2 == 0) printf("YES");
	else printf("NO");
	return 0;
}