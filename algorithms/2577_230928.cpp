// https://www.acmicpc.net/problem/2577
#include <iostream>
#include <array>

int main()
{
    unsigned int A, B, C;
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    
    long int result;
    result = A * B * C;
    
    std::array<int, 10> nums = {};
    while (result > 0) {
        // std::cout << result << std::endl;
        int i = result % 10;
        ++nums[i];
        result = result / 10;
    }
    for(auto a: nums) {
        std::cout << a << std::endl;
    }
}