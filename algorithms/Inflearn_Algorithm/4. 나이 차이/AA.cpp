// 나이 차이
// N명의 나이가 입력. 가장 나이 차이가 많이 나는 나이 차이를 출력.
// input.txt 파일을 입력으로 받아 output.txt로 결과 출력
#include <iostream>

using namespace std;
int main () {
	
	/* freopen("input.txt", "rt" , stdin); */ //채점을 위해 주석처리
	// freopen클래스는 C라이브러리에선 cstdio.h로 사용되었으나 C++에선 iostream으로 대체.
	// freopen (filename, mode, stream)
	// "input.txt"파일을 readtxt 모드로 열어 표준입력(standard input)으로 넣는다.
	
	int n, a, i, max = INT_MIN, min = INT_MAX;
	
	cin >> n;
	for (i=0; i < n; i++){
		cin >> a;
		if ( a > max ) max = a;
		if ( a < min ) min = a;
	}
	cout << max - min; 
	
	return 0;
}