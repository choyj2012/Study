#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char str[35];
	vector<int> v;
	int i;
	bool flag = true;
	scanf("%s", str);
	int len = strlen(str);

	for (i = 0; i < len; i++) {
		if (str[i] == '(')
			v.push_back(-1);

		if (str[i] == '[')
			v.push_back(-2);

		if (str[i] == ')') {
			if (!v.empty() && v.back() == -1) {
				v.pop_back();
				v.push_back(2);
			}
			else {
				int t = 0;
				while (1) {
					if (!v.empty()) {
						if (v.back() < 0) {
							if (v.back() == -1)
								break;
							else {
								flag = false;
								break;
							}
						}
						else {
							t += v.back();
							v.pop_back();
						}
					}
				}
				if (flag) {
					v.pop_back();
					v.push_back(t * 2);
				}
				else break;
			}
		}

		if (str[i] == ']') {
			if (!v.empty() && v.back() == -2) {
				v.pop_back();
				v.push_back(3);
			}
			else {
				int t = 0;
				while (1) {
					if (!v.empty()) {
						if (v.back() < 0) {
							if (v.back() == -2)
								break;
							else {
								flag = false;
								break;
							}
						}
						else {
							t += v.back();
							v.pop_back();
						}
					}
				}
				if (flag) {
					v.pop_back();
					v.push_back(t * 3);
				}
				else break;
			}
		}
	}
	if (!flag) {
		printf("0");
		return 0;
	}
	int sum = 0;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		sum += *it;
	}
	printf("%d", sum);

	return 0;
}