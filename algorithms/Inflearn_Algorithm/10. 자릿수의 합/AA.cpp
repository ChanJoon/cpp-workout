/* 10. 자릿수의 합
N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력
int digit_sum(int x) 함수를 사용할 것.
자릿수의 합이 같을 경우, 더 큰 수를 출력.
*/

#if 0
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int digit_sum(int x)
{
	cout << "get x: " << x << endl;
	int digit = 0;
	int sum = 0;
	for(int i=1; ; i *= 10)
	{
		if (x / i == 0) break;
		digit++;
	}
	cout << "Check: " << digit << endl;
	for(int idx = digit; idx == 0; idx--)
	{
		sum += x / pow(10,idx);
		double rest = x % pow(10,idx);
		x -= rest * pow(10,idx);
		cout << " sum: " << sum;
		cout << " x: " << x << endl;
	}
	return sum;
}

int main(){
	
	int N, getNum, max; // 3<= N <= 100
	int result[101] = {0};
	int digit_sum(int x);
	
	cin >> N;
	
	for(int i=0; i < N; i++)
	{
		cin >> getNum;
		result[i] = digit_sum(getNum);
	}
	
	
	max = result[0];
	for(int idx=1; idx<N; idx++)
	{
		if(result[idx] > max) max = result[idx];
	}
	cout << max;
	return 0;
}
#endif // 중도포기 나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다나는 빡대가리입니다

#include <iostream>
#include <climits>
using namespace std;

int digit_sum(int x)
{
	int tmp, sum=0;
	while(x>0)
	{
		tmp = x%10;
		sum+=tmp;
		x /= 10;
	}
	return sum;
}
int main()
{
	int N, num, sum, res;
	int max = INT_MIN;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> num;
		sum = digit_sum(num);
		if(sum>max)
		{
			max = sum;
			res = num;
		}
		else if(sum==max)
		{
			if(num>res) res=num;
		}
	}
	cout << res;
	return 0;
}


