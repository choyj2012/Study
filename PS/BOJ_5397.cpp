#include <stdio.h>
#include <list>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	scanf("%d", &n);
	getchar();
	char t;

	for (i = 1; i <= n; i++) {

		list<char> List;
		List.push_back(' ');
		List.push_back(' ');
		list<char>::iterator it = List.begin();


		while (1) {
			scanf("%c", &t);
			if (t == '\n') break;

			switch (t) {
			case '<':
				if (it == List.begin())
					break;
				else {
					it--;
				}
				break;

			case '>':
				it++;
				if (it == --List.end()) {
					it--;
					break;
				}
				break;

			case '-':
				if (it == List.begin())
					break;
				else {
					it = List.erase(it);
					it--;
				}
				break;

			default:
				List.insert(++it, t);
				it--;
				break;
			}
		}

		for (it = ++List.begin(); it != List.end(); it++) {
			printf("%c", *it);
		}
	}

	return 0;
}