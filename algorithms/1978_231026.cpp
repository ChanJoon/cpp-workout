// https://www.acmicpc.net/problem/1978
#include <iostream>

using namespace std;

int main()
{
    /* Get the number of natural numbers (e.g. N <= 100) */
    int N, n_prime = 0; // n_prime을 0으로 두지 않은 경우 틀림
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        
        /* 1 is not Prime */
        if (num > 1) {
            for (int j = 2; j <= num; ++j) {
                if (num % j == 0) {
                    if (num == j) ++n_prime;
                    break;
                }
            }
        }
    }
    cout << n_prime;

    return 0;
}