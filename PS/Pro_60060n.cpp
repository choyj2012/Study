#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct _Node {
	char t;
	bool finish = false;
	vector<pair<char, _Node*>> next;

};

_Node* ROOT;
void make_trie(vector<string> words) {

	ROOT = new _Node;
	for (int i = 0; i < words.size(); i++) {
		_Node* Nptr = ROOT;
		for (int j = 0; j < words[i].size(); j++) {
			int nextch = words[i][j] - 'a';
			
			bool isExist = false;
			for (auto k : Nptr->next) {
				if (k.first == words[i][j]) {
					isExist = true;
					Nptr = k.second;
				}
			}

			if (isExist == false) {
				_Node* temp = new _Node;
				temp->t = words[i][j];
				if (j == words[i].size() - 1) temp->finish = true;
				Nptr->next.push_back({ words[i][j], temp });
				Nptr = temp;
			}
		}
	}
}

int cnt = 0;
void dfs(_Node* nptr, string q, int idx) {

	if (idx == q.length()) {
		if (nptr->finish == true) cnt++;
		return;
	}

	if (q[idx] == '?') {
		for (auto& k : nptr->next) {
			dfs(k.second, q, idx + 1);
		}
	}
	else {
		for (auto& k : nptr->next) {
			if (k.first == q[idx])
				dfs(k.second, q, idx + 1);
		}
	}
}

int serch_trie(string q) {
	_Node* ptr = ROOT;
	cnt = 0;
	dfs(ROOT, q, 0);
	return cnt;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	make_trie(words);

	for (auto& q : queries) {
		answer.push_back(serch_trie(q));
	}
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n_word, n_query;
	vector<string> WORDS;
	vector<string> QUERY;
	scanf("%d %d", &n_word, &n_query);

	for (int i = 1; i <= n_word; i++) {
		string str;
		cin >> str;
		WORDS.push_back(str);
	}

	for (int i = 1; i <= n_query; i++) {
		string str;
		cin >> str;
		QUERY.push_back(str);
	}

	for(int k : solution(WORDS, QUERY))
		printf("%d\n", k);

	return 0;
}