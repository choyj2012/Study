#include <stdio.h>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	scanf("%d", &n);

	long long int t;
	vector<long long> stack;
	long long answer = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &t);
		int cnt = 0;

		if (!stack.empty()) {
			if (t > stack.back()) {
				cnt = 0;
				while (1) {
					if (!stack.empty() && stack.back() < t) {
						stack.pop_back();
						cnt++;
					}
					else
						break;
				}
				if (stack.empty())
					answer += cnt;
				else
					answer += cnt + 1;
			}
			else if (t == stack.back()) {
				cnt = 0;
				vector<long long>::reverse_iterator rit = stack.rbegin();
				while (1) {
					if (rit != stack.rend() && *rit == t) {
						cnt++;
					}
					else {
						cnt++;
						break;
					}
					rit++;
				}
				answer += cnt;
			}
			else if (t < stack.back()) {
				answer++;
			}
		}
		stack.push_back(t);
	}

	printf("%lld", answer);
	return 0;
}