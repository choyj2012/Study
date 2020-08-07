#include <stdio.h>

#define MAX_SIZE 100010

int n, a, q, op, k;
int cnt[MAX_SIZE];
int cnt2, cnt4, cnt6, cnt8;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		cnt[a]++;

		if (cnt[a] == 2) cnt2++;
		else if (cnt[a] == 4) {
			cnt4++; cnt2--;
		}
		else if (cnt[a] == 6) {
			cnt6++; cnt4--;
		}
		else if (cnt[a] == 8) {
			cnt8++; cnt6--;
		}
	}

	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {

		scanf(" %c %d", &op, &k);
		if (op == '+') {
			cnt[k]++;

			if (cnt[k] == 2) cnt2++;
			else if (cnt[k] == 4) {
				cnt4++; cnt2--;
			}
			else if (cnt[k] == 6) {
				cnt6++; cnt4--;
			}
			else if (cnt[k] == 8) {
				cnt8++; cnt6--;
			}
		}
		else if (op == '-') {
			cnt[k]--;

			if (cnt[k] == 1) cnt2--;
			else if (cnt[k] == 3) {
				cnt4--; cnt2++;
			}
			else if (cnt[k] == 5) {
				cnt6--; cnt4++;
			}
			else if (cnt[k] == 7) {
				cnt8--; cnt6++;
			}
		}


		if (cnt8 >= 1 || cnt6 >= 1 && cnt2 >= 1 || cnt4 >= 2 || cnt4 >= 1 && cnt2 >= 2)
			printf("YES\n");
		else printf("NO\n");

	}
}