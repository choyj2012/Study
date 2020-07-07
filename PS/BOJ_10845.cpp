#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	scanf("%d", &n);
	
	queue<int> q;
	for (i = 1; i <= n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int t;
			cin >> t;
			q.push(t);
		}
		if (str == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		if (str == "size") {
			cout << q.size() << endl;
		}
		if (str == "empty") {
			cout << q.empty() << endl;
		}
		if (str == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		if (str == "back") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
}