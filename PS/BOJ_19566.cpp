#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, E, t;
	scanf("%d %d", &N, &E);
	vector<long long> sum(N + 1, 0);
	unordered_map<long long, long long> map;
	
	map[0] = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &t);
		sum[i] = sum[i - 1] + t;

		long long k = sum[i] - (long long)E * i;
		if (map.find(k) != map.end()) map[k]++;
		else map[k] = 1;
	}

	long long answer = 0;
	for (auto k : map) {
		answer += k.second * (k.second - 1) / 2;
	}
	printf("%lld", answer);
	return 0;
}