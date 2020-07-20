#include <stdio.h>
#include <algorithm>
using namespace std;

int d[1001];
int dplr[1001];
int dprl[1001];
int answer;
int n;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}

	for (int i = 1; i <= n; i++) {
		dplr[i] = 1;
		for (int j = 1; j < i; j++) {
			if (d[i] > d[j])
				dplr[i] = max(dplr[i], dplr[j] + 1);
		}
	}

	for (int i = n; i >= 1; i--) {
		dprl[i] = 1;
		for (int j = n; j > i; j--) {
			if (d[i] > d[j])
				dprl[i] = max(dprl[i], dprl[j] + 1);
		}

		answer = max(answer, dprl[i] + dplr[i]);
	}

	printf("%d", answer - 1);
	return 0;
}