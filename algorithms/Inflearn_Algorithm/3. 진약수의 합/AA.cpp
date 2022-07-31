#include <iostream>
// 진약수의 합
//자연수 N이 주어지면 자연수 N의 진약수의 합을 출력

int main () {
	using namespace std;
	
	int n, i, result = 1;
	
	cin >> n;
	
	cout << 1;
	for  (i = 2; i < n; i++){
		if( n % i == 0){
			cout << " + " << i;
			result += i;
		}
	}
	cout << " = " << result;

 
/* 	for  (i = n; i > int(n/2); i--){
		// 절반까지만 찾을건데,
		if( n % i == 0){
			num2 = n / i;
			sum = i + num2;
			result += sum;
		}
	}	 */
	return 0;
}