#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	long long answer = 0;
	int t;
	vector<P> stack;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &t);
		P p(t, 1);


		while (!stack.empty()) {
			if (stack.back().first <= t) {
				answer += stack.back().second;
				if (stack.back().first == t) {
					p.second += stack.back().second;
				}
				stack.pop_back();
			}
			else {
				if (!stack.empty()) answer++;
				break;
			}
		}
		stack.push_back(p);
	}
	printf("%lld", answer);
	return 0;
}
