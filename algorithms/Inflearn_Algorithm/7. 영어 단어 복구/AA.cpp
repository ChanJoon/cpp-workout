/*
영어단어 복구
대소문자와 띄어쓰기가 혼합된 문자열을 소문자로만 구성된 문자열로 바꾸어 출력
*/
#if 0			// 내가 쓴 코드

#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
	char a[100];
	int i=0;
	char ch, res = 0;
	
	cin.getline(a,100);
	for(i=0; a[i] != '\0'; i++)
	{
		if( !isblank(a[i]) )
		{
			/* cout << a[i] << endl; */
			ch = tolower(a[i]);
			cout << ch;
		}
	}
	return 0;
}
#endif

// 강의 코드
#include <iostream>
using namespace std;
int main()
{
	char a[101], b[101];
	int i, p = 0;
	gets(a);
	
	for(i = 0; a[i] != '\0'; i++)
	{
		if(a[i] != ' ')
		{
			if(a[i] >= 65 && a[i] <= 90)	// ASCII 대문자 A to Z
			{
				b[p++]=a[i]+32;							// array b 에 대입한 후 p++
				// ASCII A = 65, a = 97 이므로 32를 더해주면 lowercase로 바꾸어줌
			}
			else b[p++] = a[i];
		}
	}
	b[p]='\0';			// p++ 해주므로 마지막에 NULL 넣어줌.
	cout << b;
	
	return 0;
}