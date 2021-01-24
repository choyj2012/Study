#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> parent;
vector<int> friends;

int uni_find(int node) {

	if (parent[node] == node)
		return node;

	return parent[node] = uni_find(parent[parent[node]]);
}

int main() {

//	freopen("input.txt", "r", stdin);

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		unordered_map<string, int> match;
		string name1, name2;
		parent.clear();
		friends.clear();
		parent.resize(2 * N);	for (int i = 0; i < 2 * N; i++) parent[i] = i;
		friends.resize(2 * N, 1);
		
		int k = 0;
		for (int i = 0; i < N; i++) {
			cin >> name1 >> name2;
			if (match.find(name1) == match.end()) match[name1] = k++;
			if (match.find(name2) == match.end()) match[name2] = k++;
			
			int p1 = uni_find(match[name1]);
			int p2 = uni_find(match[name2]);

			if (p1 != p2) {
				cout << friends[p1] + friends[p2] << "\n";
				parent[p2] = p1;
				friends[p1] += friends[p2];
			}

			if (p1 == p2) {
				cout << friends[p1] << "\n";
			}
		}
		
	}
}