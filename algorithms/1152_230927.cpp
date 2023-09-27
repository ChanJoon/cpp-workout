// https://www.acmicpc.net/problem/1152
#include <iostream>
#include <string>

int main()
{
    std::string input;
    
    std::getline(std::cin, input);
    
    int count = 0;
    int i = 0;
    for(int i=0; i<input.length(); ++i) {
        if(input[i] == ' ') {
            ++count;
            if (i == 0) count = 0;
        }
    }
    if(input[input.size() - 1] != ' ') ++count;
    std::cout << count << std::endl;

    return 0;
}