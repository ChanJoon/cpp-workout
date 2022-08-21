/* 11. 숫자의 총 개수(small)				*다시풀기
자연수 N이 입력, 1부터 N까지의 자연수를 적을 때 각 숫자는 몇 개씩 쓰였을까?
ex) N = 11, 1,2,3,4,5,6,7,8,9,1,0,1,1 => 13개
*/

#if 0
#include <iostream>
int main()
{
	char N[6];		// 3<= N <= 100.000
	cin.get(N,6);
	
	// 자릿수 파악..? N을 1씩 감소시키면서
	int i = 6;
	while(N[i] != "\n") i--;
	
	int j = i;
	int cnt = 0;
	while (N[j] == 0)
	{
		N[j]--;
		cout << N[j] << endl;
		cnt += cnt * (j+1);
		
		16842 = 5 x 6843 + 4 x 5843 + 3 x 743 + 2 x 53 + 1 * 9
	}
}
#endif

#include <iostream>
int main()
{
	using namespace std;
	int N, sum = 0;
	int cnt = 1, d = 9, res = 0;
	
	cin >> N;
	while (sum + d < N)		// 각 자릿수의 갯수 총합이 N 보다 커지면 break
	{
		res = res + (cnt * d);	// N보다 작은 자릿수를 가지는 모든 수의 갯수
		sum = sum + d;
		cnt++;
		d *= 10;
	}
	res += (N - sum) * cnt;
	cout << res;
	
	return 0;
}
