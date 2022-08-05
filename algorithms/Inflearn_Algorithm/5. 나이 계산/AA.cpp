/* 나이 계산
첫 줄에 주민등록증 번호가 입력됩니다.
해당 주민등록증 주인의 나이와 성별을 출력하세요.(기준 2019년)
성별은 남자 M / 여자 W로 출력.
*/

#include <iostream>
int main()
{
	/* freopen("input.txt","rt",stdin); */
	using namespace std;
	// string num[14]; not string
	char num[20];				// read individual characters
	int age;
	char sex;
	
	/* cout << (int)'9'; */ // '9'가 그대로 9로 형변환X, ASCII 57로 변환
	cin.getline(num, 20);
	if(num[7] == '1' || num[7] == '2') age = 101-( (num[0]-'0') * 10 + (int)(num[1]-'0') ) + 19;
	else age = 19 - ( (int)(num[0]-'0') * 10 + (int)(num[1]-'0') ) + 1;
	// 그러므로 char 에서 '0'을 빼주고 int 형으로 바꾸면 ASCII 48 이 빠지므로 해당 수가 나타난다.
	// '0'을 빼는것이 아니라 바뀐 int 숫자에서 48을 빼주어도 됨. ex) num[0] - 48
	
	if(num[7] == '1' || num[7] == '3') sex = 'M';
	else if (num[7] == '2' || num[7] == '4') sex = 'W';
	else return 1;
	
	cout << age << " " << sex;
	
	return 0;
}

// reference
// https://stackoverflow.com/questions/1042110/using-scanf-in-c-programs-is-faster-than-using-cin
// https://eblee-repo.tistory.com/45