// https://www.acmicpc.net/problem/2231
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main() {
    int num;
    cin >> num;

    int result = INT_MAX;

    for (int a = 1; a < num; a++) {
        string a_str = to_string(a);
        vector<int> a_vec;
        
        for (char c: a_str) {
            a_vec.push_back(c - '0');
        }
        int constructor = a;
        for (int i = 0; i < a_vec.size(); i++) {
            constructor += a_vec[i];
        }
        if ((constructor == num) && (constructor < result)) {
            result = a;
        }
    }
    if (result == INT_MAX) result = 0;
    cout << result;

    return 0;
}