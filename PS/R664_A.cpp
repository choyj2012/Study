#include <cstdio>
#include <algorithm>
using namespace std;

int b[4];
int T;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &T);

	while (T--) {
		bool zero = false;
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &b[i]);
			if (i < 3 && b[i] == 0) zero = true;
			if (b[i] % 2 == 1) cnt++;
		}
		if (cnt <= 1) {
			printf("YES\n");
			continue;
		}

		if (!zero) {
			cnt = 0;
			for (int i = 0; i < 4; i++) {
				if ((b[i] - 1) % 2 == 1) cnt++;
			}
			if (cnt <= 1) {
				printf("YES\n");
				continue;
			}
		}

		printf("NO\n");
	}
	return 0;
}