#include <cstdio>

int main() {

	freopen("input.txt", "r", stdin);

	int n, x, p;
	long long now = 0, max = -1;
	bool flag = false;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &p);

		if (now <= x) {
			now += p;
		}
		else if (flag == false && now > x) {
			flag = true;
			now -= max;
			if (now <= x) {
				now += p;
			}
			else {
				now += max;
				continue;
			}
		}
		else {
			printf("Zzz\n");
			return 0;
		}

		max = max > p ? max : p;
	}

	printf("Kkeo-eok\n");
	return 0;
}