#include <iostream>
// a에서 b까지의 자연수의 합

int main() {
	using namespace std;
	
	int a, b, i, sum=0;
	cin >> a >> b;
/*
//채점기 작동 X
	for( i = a; i < b+1; i++ ){
		cout << i << " + ";
		sum += i;
	}
	cout << "\b\b= " << sum;
	*/
	for (i=a;i<b;i++){
		cout << i << " + ";
		sum += i;
	}
	cout << i << " = ";
	cout << sum+i;
	
	return 0;
}