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
