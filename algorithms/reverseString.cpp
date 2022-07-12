#include <iostream>
int main(){
	using namespace std;
    int i, T;
    
    cin >> T;
	string str_arr[T] = {0};
	string str_buf[T];
    for (i=0;i<=T;i++){
        cin >> str_arr[i];
		istringstream iss(str_arr[i]);
		while(getline(iss, str_buf[i], ' '));
    }
	for(i=0;i<sizeof(str_buf);i++){
		cout << str_buf << "\n";
	}
    return 0;
}