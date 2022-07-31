#include <iostream>

/* 1부터 N까지의  M의 배수 총합 */ 

int main(){
	using namespace std;
	
	int n, m, i, sum=0;
	
	do {
/* 		cout << "정수 n까지의 정수 m의 배수를 계산합니다. " << endl;
		cout << "n과 m을 각각 입력하세요 " << endl; */
		cin >> n >> m;
		if ( n < 0 || m < 0) {
			cout << "입력되는 값은 양수여야합니다" << endl;
		}
	}
	while ( n < 0 || m < 0 );

	for (i=1;i<=n;i++) {
		if( i % m == 0) {
			sum += i;
		} 
	}
	cout << sum;
	
	return 0;
} 
