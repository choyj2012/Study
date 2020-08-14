#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n, t;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<int> v(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &t);
			v[i] = v[i - 1] + t;
		}

		unordered_map<int, long long> m;
		for (int i = 1; i <= n; i++) {
			v[i] -= i;
			if (m.find(v[i]) != m.end()) m[v[i]]++;
			else m[v[i]] = 1;
		}
		
		long long cnt = 0;
		for (auto i = m.begin(); i != m.end(); i++) {
			cnt += (*i).second * ((*i).second - 1) / 2;
			if ((*i).first == 0) cnt += (*i).second;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}