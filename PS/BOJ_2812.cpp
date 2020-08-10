#include <cstdio>
#include <vector>
using namespace std;

int N, K;
vector<int> s;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &N, &K);
	int len = 0;
	int num;
	while (K > 0 && (len < N)) {
		scanf("%1d", &num);
		len++;

		if (s.empty()) {
			s.push_back(num);
		}
		else if (s.back() < num) {

			while (!s.empty() && s.back() < num && K > 0) {
				s.pop_back();
				K--;
			}
			s.push_back(num);

		}
		else if (s.back() >= num)
			s.push_back(num);
	}

	while (1) {	//K개 다지웠는데 아직 입력받을거 더있는경우
		if (len == N) break;
		scanf("%1d", &num);
		s.push_back(num);
		len++;
		
	}
	for (int i = 0; i < s.size() - K; i++) {
		printf("%d", s[i]);
	}
	return 0;
}