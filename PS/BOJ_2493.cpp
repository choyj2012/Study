#include <stdio.h>
#include <vector>
using namespace std;

struct tower {
	int h;
	int idx;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	vector<tower> stack;
	
	scanf("%d", &n);
	int *answer = new int[n + 1]();
	int *data = new int[n + 1];

	for (i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}

	for (i = n; i >= 1; i--) {
		tower t;
		t.h = data[i];
		t.idx = i;

		if (stack.empty()) {
			stack.push_back(t);
		}
		else {
			while (!stack.empty() && t.h > stack.back().h)
			{
				answer[stack.back().idx] = t.idx;
				stack.pop_back();
			}
			stack.push_back(t);
		}
	}

	for (i = 1; i <= n; i++) {
		printf("%d ", answer[i]);
	}

	delete[] data;
	delete[] answer;

	return 0;
}