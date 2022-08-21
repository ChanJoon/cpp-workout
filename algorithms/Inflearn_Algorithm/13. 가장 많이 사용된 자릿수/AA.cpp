/* 13. 가장 많이 사용된 자릿수
N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력
ex) 1230565825 => 5
답이 여러 개일 경우 그 중 가장 큰 수를 출력
*/

#if 0
#include <iostream>
int main()
{
	using namespace std;
	
	long long N;
	int num;
	int cnt[10] = {0};
	cin >> N;
	// 어떤 수가 가장 많은지, 각 자릿수별로 카운트-> 나머지 이용
	while ( N >= 1)
	{
		cout << "num: " << N << endl;
		num = N % 10;
		cnt[num]++;
		N = N / 10;
	}
	int i, idx;
	int max = 0;
	for (i = 0; i < 10; i++)
	{
/* 		cout << "Check cnt: " << cnt[i] << endl; */
		if(cnt[i] >= max){
		    max = cnt[i];
		    idx = i+1;
		}
/* 		cout << "max: " << idx << endl; */
	}
	cout << idx;
	return 0;
}
#endif			// 매우 큰 수가 들어올 경우 계산이 안됌.

#include <iostream>
#include <climits>
int ch[10];
int main()
{
	using namespace std;
	int i, digit, res;
	int max = INT_MIN;
	char a[101];
	cin >> a;
	
	for (i = 0; a[i] != '\0'; i++)
	{
		digit = a[i] - 48;			// i번째 자릿수의 숫자
		ch[digit]++;					// 해당 숫자 index의 배열 element 증가
	}
	for(i = 0; i < 10; i++)
	{
		if (ch[i] >= max)
		{
			max = ch[i];
			res = i;
		}
	}
	cout << res;
	return 0;
}