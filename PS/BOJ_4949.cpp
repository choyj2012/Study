#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;



int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (1) {
		vector<char> v;
		char str[110];
		scanf("%[^\n]s", str);
		getchar();
		if (str[0] == '.') break;

		int len = strlen(str);
		int i;
		for (i = 0; i < len; i++) {
			if (str[i] == '(') {
				v.push_back('(');
			}
			if (str[i] == ')') {
				if (!v.empty() && v.back() == '(') v.pop_back();
				else {
					v.push_back(')');
					break;
				}
			}
			if (str[i] == '[') {
				v.push_back('[');
			}
			if (str[i] == ']') {
				if (!v.empty() && v.back() == '[') v.pop_back();
				else {
					v.push_back(']');
					break;
				}
			}
		}
		if (v.size() == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}