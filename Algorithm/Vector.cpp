#include <vector>
#include <iostream>
using namespace std;

/*
멤버 함수
v.begin();		시작점 iterator로 반환
v.end();		끝점 iterator로 반환

v.size();		size반환
v.max_size();		담을 수 있는 최대 원소의 개수 반환
v.capacity();		메모리 크기 반환
v.resize();		size재설정
v.empty();		비어있는지 확인
v.reserve();		메모리 미리할당
v.clear();

v.assign();		값 할당
v.at();
v.push_back();
v.pop_back();
*/
void VectorLoop(vector<int> v);
void VectorDestructor();
void PrintVector(vector<int> v);
void VectorAssign(vector<int> v);
void DynamicVector();

int main() {

	vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> num2(5, 1);	//{1,1,1,1,1}
	vector<int> num3(num2);	//{1,1,1,1,1}
	vector<int> num4(num.begin() + 3, num.end() - 3);	//{4,5,6,7}

//	VectorLoop(num);
//	VectorDestructor();
//	VectorAssign(num);

	return 0;
}

void DynamicVector() {
	vector<int>* dv = new vector<int>(10000, 1);
	printf("%d ", dv->at(1));
	printf("%d ", (*dv)[1]);

	delete dv;	//dv->~vector();
}

void VectorAssign(vector<int> v) {
	vector<int> v2;
	v2.assign(v.begin(), v.end());	//copy
	PrintVector(v2);

	vector<int> v3;
	v3.assign(5, 100);
	PrintVector(v3);

	vector<int> v4;
	v4.assign({ 1,2,3,4,5 });
	PrintVector(v4);
}

void VectorLoop(vector<int> v) {
	vector<int>::iterator it; //반복자(iterator)
	for (it = v.begin(); it != v.end(); it++) {	//iterator를 통한 접근
		cout << *it;
	}
	cout << endl;
	
	vector<int>::reverse_iterator rit;	//역반복자(reverse_iterator)
	for (rit = v.rbegin(); rit != v.rend(); rit++) {
		cout << *rit;
	}
	cout << endl;
	int i;
	vector<int>::iterator it2 = v.begin();
	for (i = 0; i < v.size(); i++) {	//[]를 통한 접근
		cout << it2[i];
	}
	cout << endl;

	for (i = 0; i < v.size(); i++) {	//[]를 통한 접근
		cout << v[i];
	}
	cout << endl;
}

void VectorDestructor() {	//vector 메모리해제
	vector<int> vi(5, 1);
	vi.resize(7);
	PrintVector(vi);
	cout << vi.size() << " " << vi.capacity() << endl;	//size:5 capacity:5

	vi.clear();
	cout << vi.size() << " " << vi.capacity() << endl;	//size:0 capacity:5

	vector<int>().swap(vi);	//vi.~vector();
	cout << vi.size() << " " << vi.capacity() << endl; //size:0 capacity:0

	vi.reserve(5);
	cout << vi.size() << " " << vi.capacity() << endl; //size:0 capacity:5

	//resize후 shrink_to_fit
	vi.resize(0);
	vi.shrink_to_fit();	//swap을 방법을 대체. (c++11)
	cout << vi.size() << " " << vi.capacity() << endl; //size:0 capacity:0
	
}

void PrintVector(vector<int> v) {
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
