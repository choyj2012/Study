#include <vector>
#include <iostream>
using namespace std;


int main() {

	vector<int> vi(5);
	
	vi.clear();
	cout << vi.size() << vi.capacity() << endl;
	
	vector<int>().swap(vi);
	cout << vi.size() << vi.capacity() << endl;

	//	vi.~vector();
	vi.begin();
	vi.end();
	return 0;
}