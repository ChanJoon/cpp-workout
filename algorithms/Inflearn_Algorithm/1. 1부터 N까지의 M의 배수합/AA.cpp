#include <iostream>

/* 1���� N������  M�� ��� ���� */ 

int main(){
	using namespace std;
	
	int n, m, i, sum=0;
	
	do {
/* 		cout << "���� n������ ���� m�� ����� ����մϴ�. " << endl;
		cout << "n�� m�� ���� �Է��ϼ��� " << endl; */
		cin >> n >> m;
		if ( n < 0 || m < 0) {
			cout << "�ԷµǴ� ���� ��������մϴ�" << endl;
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
