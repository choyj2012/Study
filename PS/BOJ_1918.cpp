#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int oprank(char op) {
	if (op == '*' || op == '/') return 1;
	else if (op == '+' || op == '-') return 2; 
	else return 3;		//'('
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<char> v;
	char str[110];

	scanf("%s", str);
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')	//알파벳일경우
			printf("%c", str[i]);
		else if (str[i] == ')') {	//닫는괄호일경우
				while (!v.empty() && v.back() != '(') {
					printf("%c", v.back());
					v.pop_back();
				}
				v.pop_back();
		}
		else if (str[i] == '(')v.push_back(str[i]);	//여는괄호일경우
		else {	//연산자 (+, -, *, /)
			while (!v.empty() && oprank(v.back()) <= oprank(str[i])) {
				printf("%c", v.back());
				v.pop_back();
			}
			v.push_back(str[i]);
		}
	}
	while (!v.empty()) {
		printf("%c", v.back());
		v.pop_back();
	}
	return 0;
}