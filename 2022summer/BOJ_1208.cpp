#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 41

int N, S;
long long ans = 0;
vector<int> num, A, B;

void setA(int idx, int sum) {
	if (idx >= N / 2) return;
	setA(idx + 1, sum);
	sum += num[idx];
	if (sum == S) ans++;
	A.push_back(sum);
	setA(idx + 1, sum);
}

void setB(int idx, int sum) {
	if (idx >= N) return;
	setB(idx + 1, sum);
	sum += num[idx];
	if (sum == S) ans++;
	B.push_back(sum);
	setB(idx + 1, sum);
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &S);
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}

	setA(0, 0);
	setB(N/2, 0);
	
	sort(B.begin(), B.end());
	for (int a : A) {
		auto e = upper_bound(B.begin(), B.end(), S - a);
		auto s = lower_bound(B.begin(), B.end(), S - a);

		ans += (long long)(e - s);
	}

	printf("%d", ans);
	return 0;
}