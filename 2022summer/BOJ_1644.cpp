#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> p;

void getPrime(int n) {

	vector<int> c(n + 1, -1);

	for (int i = 2; i*i <= n; i++) {
		if (c[i] == -1) {
			for (int j = i * 2; j <= n; j += i) {
				c[j] = 1;
			}
		}
	}

	for (int i = 2; i <= n; i++)
		if (c[i] == -1) p.push_back(i);
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	if (N == 1) { printf("0"); return 0; }
	getPrime(N);

	auto l = p.begin();
	auto r = p.begin();
	int sum = p[0];
	int ans = 0;
	
	while (1) {

		if (sum < N) {
			r++;
			if (r == p.end()) break;
			sum += *r;
		}
		else if (sum > N) {
			sum -= *l;
			l++;
			if (l == p.end()) break;
		}
		else {	//sum == N
			ans++;
			r++;
			if (r == p.end()) break;
			sum += *r;
		}

	}

	printf("%d", ans);
	return 0;
}