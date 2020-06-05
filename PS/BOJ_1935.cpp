#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double op(double a, double b, char op) {
	switch(op){
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	int val[30];	//A=0, B=1 ... 
	string str;

	scanf("%d", &n);
	cin >> str;

	for(i=0; i<n; i++) {
		scanf("%d", &val[i]);
	}

	string::iterator it;
	vector<double> stack;

	for (it = str.begin(); it != str.end(); it++) {
		
		if (*it >= 'A' && *it <= 'Z') {
			stack.push_back((double)val[*it - 'A']);
		}
		else {
			double t1 = stack.back();
			stack.pop_back();
			double t2 = stack.back();
			stack.pop_back();
			stack.push_back(op(t2, t1, *it));
		}
	}

	printf("%.2lf", stack.back());
	return 0;
}