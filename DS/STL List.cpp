#include <iostream>
#include <list>
using namespace std;

/*
list.begin();
*/

int main() {
	list<int> List;
	List.push_back(1);
	List.push_back(2);
	List.push_back(3);
	list<int>::iterator it = List.begin();
	it++;
	cout << *it << endl << endl;

	List.insert(++it, 4);
	cout << *(--it) << endl;


	cout << *it << endl;
	for (it = List.begin(); it != List.end(); it++) {
		cout << *it << ' ';
	}
	return 0;
}