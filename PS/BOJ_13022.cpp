#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int Wc, Oc, Lc, Fc;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	cin >> str;
	int i;
	for (i = 0; i < str.length(); i++) {
		char t = str[i];

		if (t == 'w') {
			Wc++;
			if (Oc != 0 || Lc != 0 || Fc != 0) break;
		}

		if (t == 'o') {
			Oc++;
			if (Wc < Oc || Lc != 0 || Fc != 0) break;
		}

		if (t == 'l') {
			Lc++;
			if (Wc != Oc || Oc < Lc || Fc != 0) break;
		}
		
		if (t == 'f') {
			Fc++;
			if (Oc != Lc || Lc < Fc) break;

			if (Lc == Fc) {
				Wc = Oc = Lc = Fc = 0;
			}
		}
	}

	if (Wc == Oc && Oc == Lc && Lc == Fc) printf("1");
	else printf("0");
	return 0;
}