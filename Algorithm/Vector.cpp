#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int>::iterator it; //반복자(iterator)
	for (it = num.begin(); it != num.end(); it++) {
		cout << *it;
	}
	cout << endl;
	vector<int>::iterator num_it = num.begin();
	cout << num[5] << num_it[5] << endl;	//iterator를 통한 접근
	

	//vector 메모리해제
	vector<int> vi(5);
	vi.clear();
	cout << vi.size() << vi.capacity() << endl;	//size:0 capacity:5
	
	vector<int>().swap(vi);
	cout << vi.size() << vi.capacity() << endl; //size:0 capacity:0

	//vi.~vector();

	return 0;
}