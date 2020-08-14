#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 2<<11-1

int n, m;
int I[210];
int J[210];

bool compare(int a, int b) {
	return a > b;
}
int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &I[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &J[i]);
	}
	int answer = 1023;
	for (int k = 1023; k >= 0; k--) {

		bool flag = true;
		for (int i = 0; i < n; i++) {
			bool checki = false;
			for (int j = 0; j < m; j++) {
				if (((I[i] & J[j]) | k) == k) {
					checki = true;
					break;
				}
			}
			if (checki == false) {
				flag = false;
				break;
			}
		}
		if (flag) answer = k;
	}
	printf("%d", answer);
	return 0;
}