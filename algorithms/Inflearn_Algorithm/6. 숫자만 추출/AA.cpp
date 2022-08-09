/*
숫자만 추출
문자와 숫자가 섞여있는 문자열에서 숫자만 추출 / 그 순서대로 자연수를 만듦.
만들어진 자연수와 그 자연수의 약수 개수를 출력
*/
#if 0			// 내가 쓴 코드

#include <iostream>
#include <cmath>
using namespace std;
int main() {
	
	char input[12];
	int i, idx=0;
	int num[12] = {0};
	int result[12] = {0};
	
	cin.getline(input, 12);
	for(i=0; i<sizeof(input); i++)
	{
		if ( input[i] > 47 && input[i] < 58)
		{
			num[idx] = input[i] - '0';
			idx++;
		}
	}
	
	idx = 0;
	for(i=0; i<sizeof(num); i++)
	{
		if(num[i] == 0)
		{
			num = num + 1;
		}
		if (num[i] >= 0 || num[i] < 10)
		{
			result[idx] = num[i];
			idx++;
			cout << result[idx] << endl;
		}
	}

	for(i=0; i<sizeof(result); i++)
	{
		cout << result[i] * pow(10, sizeof(result) - i - 1);
	}
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main()
{
	char a[100];
	int res=0, cnt=0, i;
	
	cin.getline(a,100);
	for (i=0; a[i] != '\0'; i++)
	{
		if(a[i] >=48 && a[i] <=57)
		{
			// 아 바로 해버리면 0이면 어차피 안나온다.
			res = res*10 + (a[i] - 48);
			// 일의 자리수 * 10 해서 자리수 올려주고, + 다음 숫자를 일의 자리수로
		}
	}
	cout << res << endl;		// 여기까지 자연수 출력
	
	// 약수의 개수 출력
	for(i=1; i<=res; i++)
	{
		if(res % i == 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}