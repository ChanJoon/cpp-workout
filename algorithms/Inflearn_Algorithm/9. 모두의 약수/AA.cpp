/* 9. 모두의 약수
자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램
출력은 1부터 차례대로 약수의 개수만 출력하면 됩니다.
ex) 1 2 2 3 2 4 2 4
*/

#if 0
#include <iostream>
int main(){
	using namespace std;
	
	int N; // 5<= N <= 50,000
	cin >> N;
	for (int i=1; i <= N; i++)
	{
		int cnt = 0;
		for(int a = 1; a <= i; a++)
		{
			if(i % a == 0)
				cnt++;
		}
		cout << cnt << " ";
	}
	return 0;
}
#endif // 이렇게 짜면 Time Limit에 걸린다 (1s)

/* 역으로 생각하여 어떤 수의 배수는 그 수를 약수로 가지게 된다.
따라서, 1부터 N 까지의 배수들을 카운트하여 출력한다. */

#if 0
#include <iostream>
#include <array>
int main(){
	using namespace std;
	
	int N;
	cin >> N;
	
	// array<int, N> cnt = {0};
	// int cnt[N] = {0}; Dynamic Array
	int cnt[50000] = {-1};
	for (int i=1; i<= N; i++)
	{
		for (int j = 1; i*j <= N; j++)
		{
			cnt[i*j] = cnt[i*j] + 1;
		}
		
	}
	for(int idx = 1; idx <= N; idx ++){
		// 왜 cnt[idx] == 0 같은 조건은 안되는걸까?
		cout << cnt[idx] << " ";
	}
	return 0;
}
#endif // 이렇게 하여도 Time Limit에 걸림...

#include <iostream>
int cnt[50001];
int main(){
	using namespace std;
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j+=i)
		{
			cnt[j]++;
		}
	}
	for (int idx = 1; idx<=n; idx++)
	{
		cout << cnt[idx] << " ";
	}
	return 0;
}