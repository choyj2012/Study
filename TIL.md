TIL (2020.05.20~)
=============

## 2020.05.20

### 1. STL vector
- vector 관련 여러가지 Vector.cpp
- vector 메모리 해제방법   
  clear() : 내부 데이터만 초기화, 메모리 해제x
  ```
  vector<int> v(5);
  vector<int>().swap(v); //swap 사용
  ```
  ```
  vector<int> v(5);
  v.~vector<int>; //소멸자사용
  ```
### 2. explicit 키워드
- 자신이 원하지 않은 형변환이 일어나지 않도록 제한하는 키워드.
- [explicit키워드 이해하기](https://dydtjr1128.github.io/cpp/2019/07/13/Cpp-explicit-keyowrd.html)
### 3. markdown
- [markdown 작성법](https://gist.github.com/ihoneymon/652be052a0727ad59601)

## 2020.05.21

### 1. STL vector
- vector 메모리 해제방법추가(C+11)   
  ```
  vector<int> v(5, 1);  //{1, 1, 1, 1, 1}
  v.resize(0)
  v.shrink_to_fit();
  ```
- push_back과 emplace_back차이   
  [차이설명](https://shaeod.tistory.com/630)
### 2. C++ 동적할당
- new 연산자
- delete 연산자
  ```
  int var = new int;
  delete var;
  int arr = new int[10];
  delete[] arr;
  int *arr2[5] = new int[10][5];  //변수 사용x
  delete[] arr2;
  
  int **arr3 = new int*[10];
  for (int i = 0; i < 10; i++)
    mat[i] = new int[10];
  for (int i = 0; i < r; i++)
    delete [] arr3[i];
  delete [] arr3;
  ```
### 3. C++ 특수멤버함수
- [특수 멤버함수와 defalut, delete키워드](http://egloos.zum.com/sweeper/v/2995404)

## 2020.05.22

### 1. Stack
- LIFO(Last In First Out)
- 함수목록   
~~CreateStack - 스택 생성   
StackPush - 원소 삽입   
StackPop - 원소 삭제   
Top - top 원소 반환   
isEmpty - 스택이 비었는지 여부   
isFull - 스택이 가득 찼는지 여부~~

## 2020.5.23
##### (다풀었는데 12시지남ㅠㅠ)
### 1. BOJ문제풀이
- [BOJ2292](https://www.acmicpc.net/problem/2292)
- [BOJ2879](https://www.acmicpc.net/problem/2879)
- [BOJ3000](https://www.acmicpc.net/problem/3000)

## 2020.5.24
### 1. BOJ문제풀이
- [BOJ1874](https://www.acmicpc.net/problem/1874)
- [BOJ2193](https://www.acmicpc.net/problem/2193)

## 2020.5.25
### 1. Stack구현중(C++)

## 2020.5.26
### 1. Stack구현끝
- C++ template
- Class 멤버함수 외부선언
- 동적할당 & delete
- nullptr
### 2. BOJ문제풀이
- [BOJ1918](https://www.acmicpc.net/problem/1918)
- [BOJ4949](https://www.acmicpc.net/problem/4949)
- [BOJ9012](https://www.acmicpc.net/problem/9012)
- [BOJ10773](https://www.acmicpc.net/problem/10773)
- [BOJ10828](https://www.acmicpc.net/problem/10828)

## 2020.5.27
### 1. BOJ문제풀이
- [BOJ10799](https://www.acmicpc.net/problem/10799)

## 2020.5.30
### C++ Value type
- glvalue(lvalue + xvalue)
- rvalue(prvalue + xvalue)
- lvalue : identity를 가지면서 move될 수 없는 값
- xvalue : identity를 가지면서 move될 수 있는 값
- prvalue : identity를 가지지 않으면서 move될 수 있는 값
### C++ 참조자
- 좌측 값 참조 &
- 우측 값 참조 && 와 std::move()
	- [Rvalue reference](https://spikez.tistory.com/305)