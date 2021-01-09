#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	vector<int> init(n);
	vector<int> ltor(n);
	vector<int> rtol(n);

	
	for (int i = 0; i < n; i++) {
		scanf("%d", &init[i]);
	}

	ltor[0] = 1;
	for (int i = 1; i < n; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (init[j] > init[i]) m = max(m, ltor[j]);
		}
		ltor[i] = m + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int m = 0;
		for (int j = n - 1; j > i; j--) {
			if (init[j] > init[i]) m = max(m, rtol[j]);
		}
		rtol[i] = m + 1;
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer = max(answer, ltor[i] + rtol[i] - 1);
	}

	printf("%d", answer);
	return 0;
}