#include <cstdio>

using namespace std;

long long solution(int w, int h) {
	long long answer = 0;

	long long prev = 0;
	long long div;
	long long rem;
	for (long long i = 1; i <= w / 2 + 1; i++) {
		div = h * i / w;
		rem = h * i % w;

		if (i == w / 2 + 1) break;
		answer += div - prev;
		prev = div;
		if (rem > 0) answer++;
	}

	answer *= 2;
	if (w % 2 == 1) {
		answer += div - prev;
		if (rem > 0) answer++;
	}
	return (long long)w*h - answer;
}

int gcd(int a, int b) {
	return a % b == 0 ? b : gcd(b, a % b);
}
long long solution2(int w, int h) {
	long long answer = 1;
	long long whole = (long long)w * h;
	long long broken = w + h - gcd(w, h);
	return answer = whole - broken;
}

long long solution3(int w, int h) {
	long long answer = 0;

	for (int i = 0; i < w; ++i) {
		answer += (int)((double)h*i / w);
		printf("%d %d\n", i, (int)((double)h*i / w));
	}

	return 2 * answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	int w, h;
	scanf("%d %d", &w, &h);
	printf("%ld", solution3(w, h));
}