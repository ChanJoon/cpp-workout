// https://www.acmicpc.net/problem/2562
#include <iostream>

int main()
{
    int input;
    int max = -1;
    int where_max;
    for(int i = 0; i < 10; ++i) {
        std::cin >> input;
        if(input > max) {
            max = input;
            where_max = i;
        }
    }
    std::cout << max << std::endl << where_max+1 << std::endl;


    return 0;
}