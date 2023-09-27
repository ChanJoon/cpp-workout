// https://www.acmicpc.net/problem/1157
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 26> alphabet = {0}; // A to Z
    int index; // index of alphabet
    
    std::string input;
    char c; // input elements
    std::getline(std::cin, input);
    
    // Store the number of lower case alphabet
    for(size_t i=0; i<input.length(); ++i) {
        c = (char) tolower(input[i]);
        index = c - 'a';
        ++alphabet[index];
    }
    
    int max = -1;
    int where_max;
    // Find the most frequently used alphabet character
    for(size_t j=0; j<alphabet.size(); ++j) {
        if(alphabet[j] > max) {
            max = alphabet[j];
            where_max = j;
        }
    }
    std::sort(alphabet.begin(), alphabet.end(), std::greater<int>());
    if(alphabet[0] == alphabet[1]) std::cout << "?" << std::endl;
    else std::cout << (char) toupper(where_max + 'a') << std::endl;


    return 0;
}