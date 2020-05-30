//https://dydtjr1128.github.io/cpp/2019/06/10/Cpp-values.html

#include <iostream>
using namespace std;

/*
			   expression
		glvalue			 rvalue
	lvalue		 xvalue		  prvalue

lvalue : identity를 가지면서 move될 수 없는 표현식들
xvalue : identity를 가지면서 move될 수 있는 표현식들(std::move())
prvalue : identity를 가지고있지 않으면서 move될 수 있는 표현식들
glvalue : identity를 가지고있는 표현식들(lvalue + xvlaue)
rvalue : move될 수 있는 표현식들(prvalue + xvalue)
x : identity를 가지고 있지 않으면서 move될 수 없는것들
*/

int& ref(int&);
int ref2(int&);

int main() {

	int a = 10; //숫자 리터럴 -> Prvalue
	char b = 'a'; //문자 리터럴 -> Prvalue

	enum Color { Red, Green, Blue };
	Color color;
	color = Red;	//상수 구분자 -> Rrvalue

	int c = a + 1;	//이항 연산자의 결과 -> Pralue

	int *p;
	p = &a;	//단항 연산자 &의 피연산자 -> Lvalue, Return 값 -> Rvalue

	int d = *p;	//단항 연산자 *의 Return 값 -> Lvalue
	*p = 11;
	cout << a << endl;
	*(p + 0) = 12;	//피연산자로 Rvalue도 가능
	cout << a << endl;

	++a;	//전위 연산자의 결과 -> Lvalue;
	a++;	//후위 연산자의 결과 -> Rvalue;

	int s = 5;
	int k = 10;
	ref(s) *= 5;	//함수의 Return타입이 레퍼런스인 경우 -> Lvalue
	cout << ref2(s) << endl;	//이외는 -> Rvalue
	cout << s << endl;

	const char *str = "Hello World";
	const char *str2 = "Hello World";
	cout << &str << endl;
	cout << &str2 << endl;
	return 0;
}

int& ref(int& a) {
	a = a + 5;
	return a;
}

int ref2(int& a) {
	a = a + 5;
	return a;
}
