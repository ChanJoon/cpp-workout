/*
올바른 괄호
괄호가 입력되었을 때 괄호의 쌍이 맞으면 YES 아니면 NO 출력
*/
# if 0					// 내가 쓴 코드

#include <iostream>
using namespace std;
int main() {
	
	int i, cnt=0;
	char a[30];
	
	cin.getline(a,30);
	for (i=0; a[i] != '\0'; i++)
	{
		if(a[0] == ')' || a[0] == '}' || a[0] == ']' ) {cnt++; break;}
		if (a[i] == '(' || a[i] == '{' || a[i] == '[') cnt ++;
		if (a[i] == ')' || a[i] == '}' || a[i] == ']') cnt --;
	}
	// 괄호의 갯수만 보기때문에 )로 시작하거나 (로 끝나더라도 YES를 출력함.
	if (a[i-1] == '(' || a[i-1] == '{' || a[i-1] == '[') cnt = 100;
	
	if(cnt == 0) cout << "YES";
	else cout << "NO";
	
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main() {
	// cnt 가 음수일 때 그냥 break 하면 모든 예외적인 case 해결가능
	
	char a[100];
	int i, cnt = 0;
	
	cin.getline(a,100);
	for(i=0; a[i] != '\0'; i++)
	{
		if( a[i] == '(') cnt ++;
		else if ( a[i] == ')') cnt --;
		if( cnt < 0 ) break;
	}
	if(cnt == 0) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}