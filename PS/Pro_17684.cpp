#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct _node {
	_node *next[26];
	int index = -1;
}NODE;

vector<int> solution(string msg) {
	vector<int> answer;

	NODE *root = new NODE();
	int lastidx = 1;
	for (int i = 0; i < 26; i++) {
		NODE *tmp = new NODE();
		root->next[i] = tmp;
		root->next[i]->index = lastidx++;
	}

	
	int stridx = 0;
	while (1) {

		NODE *ptr = root;
		while (stridx < msg.length()) {
			if (ptr->next[msg[stridx] - 'A'] != nullptr) {
				ptr = ptr->next[msg[stridx] - 'A'];
				stridx++;
			}
			else {
				answer.push_back(ptr->index);
				NODE *tmp = new NODE();
				tmp->index = lastidx++;
				ptr->next[msg[stridx] - 'A'] = tmp;
				break;
			}
		}

		if (stridx >= msg.length()) {
			answer.push_back(ptr->index);
			break;
		}
	}
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);

	string str;
	cin >> str;
	for (auto k : solution(str)) {
		cout << k << " ";
	}
	return 0;
}