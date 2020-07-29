#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

int n, m;
list<string> dd;
map<string, int> check;


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	string str;
	for (int i = 1; i <= m; i++) {
		cin >> str;
		dd.push_back(str);
		check[str]++;
	}

	for (auto i = dd.begin(); i != dd.end() && n > 0; i++) {
		if (check[*i] - 1 == 0) {
			cout << *i << '\n';
			n--;
		}
		else
			check[*i]--;
	}
}