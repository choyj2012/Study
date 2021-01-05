/*
*	Segment Tree
*	Bottom-up방식
*	구간(key)내 최대값중의 최소값 검색
*/


#include <stdio.h>

#define N 600010
#define INF 987654321

int n, i, t;
int size;
int Tree[N];

int max(int i, int j) {
	if (i > j) return i;
	else return j;
}
int min(int i, int j) {
	if (i > j) return j;
	else return i;
}
int Query(int L, int R);

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	n = 200000;
//	int* Tree = new int[size * 2];

//-----------------Tree 구성----------------	-//
	for (size = 1; size < n; size *= 2);
	for (i = size; i < size + n; i++) {
		scanf("%d", &t);
		Tree[i] = t;
	}
	for (i = size + n; i < size * 2; i++) {
		Tree[i] = INF;
	}
	for (i = size - 1; i > 0; i--) {
		Tree[i] = max(Tree[i * 2], Tree[i * 2 + 1]);
	}
//-------------------------------------------//

	int key = 3;
	for (i = 1; i <= n - key + 1; i++) {
		int tmp = Query(i, i + 2);
		printf("%d~%d : %d\n", i, i + 2, tmp);
	}

	return 0;
}

int Query(int L, int R) {
	
	int maxv = 0;
	L += size - 1;
	R += size - 1;

	for (; L < R; L /= 2, R /= 2) {
		if (L % 2) maxv = max(maxv, Tree[L++]);
		if (!(R % 2)) maxv = max(maxv, Tree[R--]);
	}
	if (L == R) maxv = max(maxv, Tree[L]);
	return maxv;
}