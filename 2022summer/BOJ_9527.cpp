#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

ll N, M;
ll cnt[100];
ll t;

void tobin(ll n, vector<int> &v) {
	if (n <= 1) {
		v.push_back(n);
		return;
	}
	tobin(n / 2, v);
	v.push_back(n % 2);
}

ll sol(vector<int> n) {
	ll cnt1 = 0;
	ll ans = 0;
	int idx = n.size() - 1;
	for (int t : n) {
		if (t == 1) {
			ans += cnt[idx] + (1LL << idx)*cnt1;
			cnt1++;
		}
		idx--;
	}
	return ans;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%lld %lld", &N, &M);

	t = 2;
	cnt[0] = 1;
	for (int i = 1; i < 55; i++) {
		cnt[i] = (t / 2 + (cnt[i - 1] - 1) * 2) + 1;
		t *= 2;
	}
	
	vector<int> n1b;
	vector<int> n2b;
	tobin(N - 1, n1b);
	tobin(M, n2b);

	printf("%lld", sol(n2b) - sol(n1b));
	return 0;
}