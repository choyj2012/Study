#include <stdio.h>

#define MAX_SIZE 100010

int n, a, q, op, k;
int cnt[MAX_SIZE];
int cnt2[MAX_SIZE];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		cnt[a]++;

		cnt2[cnt[a]]++;
	}

	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {

		scanf(" %c %d", &op, &k);
		if (op == '+') {
			cnt[k]++;
			cnt2[cnt[k]]++;
		}
		else if (op == '-') {
			cnt2[cnt[k]]--;
			cnt[k]--;
		}

		bool flag = false;
		if (cnt2[8] > 0) flag = 1;
		if (cnt2[6] > 0 && cnt2[2] >= 2) flag = 1;
		if (cnt2[4] >= 2) flag = 1;
		if (cnt2[4] > 0 && cnt2[2] >= 3) flag = 1;


		if (flag)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}