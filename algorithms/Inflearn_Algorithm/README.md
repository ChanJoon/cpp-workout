# 날짜별 메모

## 0731
> ### 01 Backspace
> ###### 아래 코드를 통해 이전에 출력된 내용을 지우게 만들 수 있다.
> ###### for 반복문을 통해 반복출력한 후에 마지막부분 수정할 때 용이
>    ```cpp
>    #include <iostream>
>    int main() {
>     for(i=0;i<10;i++){
>       std::cout << i << " + ";
>     }
>     std::cout << "\b\b";
> 
>    return 0;
>    }
>    ```
> ### 02 freopen
>
>    ```cpp
>    freopen("input.txt", "rt", stdin);
>    ```
>  
>	###### freopen (filename, mode, stream)
>	###### "input.txt"파일을 readtxt 모드로 열어 표준입력(standard input)으로 넣는다.
> ###### stdin이면 cin이 나올때마다 값을 input.txt에서 읽어낸 내용을 넣어준다.
>  ###### fclose()를 호출해주는 것이 정석이나, stdin만 사용할 경우 없어도 무방.
> > <a> https://m.cplusplus.com/reference/cstdio/freopen/
> #### <stdio.h>, \<cstdio\>, \<iostream\> 의 차이
>	###### freopen클래스는 C라이브러리에선 <stdio.h> 로 사용되었으나 C++에선 iostream으로 대체
>	###### stdio.h는 global namespace를 사용, cstdio는 std라는 namespace를 사용
>
>	###### \<iostream\>는 객체에 %를 사용하지 않아서, 더 안전하다. 더 자세한 내용은 아래 링크에 나와있다.
> > <a> https://isocpp.org/wiki/faq/input-output#iostream-vs-stdio
  
  
## 0808
  > ### 01 Unknown array size
  > ###### char[size]로 선언된 array에 문자를 입력. size보다 작은 입력이 들어왔을 때 입력크기만큼 array를 정하고 싶었다.
  > > <a> https://stackoverflow.com/questions/22432755/how-to-initialize-an-array-whose-size-is-initially-unknown
  > > <a> https://stackoverflow.com/questions/3857229/check-if-c-array-is-null
  > ###### 다음과 같은 동적할당에 대한 설명을 찾을 수 있었는데, Primer 교재의 Ch4를 끝낸 후에 같이 살펴보고 Pointer와 Dynamic Array에 익숙해지면 좋겠다.
  >
  > ### 02 isblank
  > ###### 입력된 문자열에 띄어쓰기를 찾는 방법
>    ```cpp
>     if( a[i] == ' ' )     // 또는
>     if( isblank(a[i] )
>   ```
  > > <a> https://cplusplus.com/reference/cctype/isblank/
  >
  > ### 03 Lowercase
  > > <a> https://www.programiz.com/cpp-programming/library-function/cctype/tolower
  > ###### tolower();을 이용하여 소문자로 바꿀 수 있다. <cctype> or <ctype.h> 헤더파일이 필요하다.
>   ```cpp
  > #include <cctype>
  > char ch = tolower('A');
>   ```
  > ### 04 주석달기
  > ###### C++은 보통 /* */ 혹은 // 을 이용하여 주석처리하는데, /* */ 안에 새로운 /* */가 존재하면 닫히는 */을 주석의 끝으로 처리하여 이중 주석이 불가능하다.
  > ###### 이 경우 #if 0 #endif를 이용하면 전체주석처리가 가능하며 이 안에 /* */를 사용하는 것은 가능하다.

## 0815
  > ### 01 시간복잡도
  > ###### 1부터 N까지의 모든 약수를 구하면 시간복잡도가 n*n이 된다.
  > ###### N까지의 배수 갯수가 각 수들의 약수 갯수 임을 이용함.
  > ```cpp
  >   for(int i=1; i<=n; i++)
  >   {
  >	   for(int j=i; j<=n; j+=i)  // i번째 수의 배수를 찾아서 해당 수의 cnt++
  >	   {
  >		  cnt[j]++;
  >	   }
  >   }
  >   for (int idx = 1; idx<=n; idx++)
  >   {
  >	   cout << cnt[idx] << " ";
  >   }
  > ```
  > ### 02 Array
  > ###### Array선언 방식은 여러가지가 있다.
> ```cpp
  >   int a[5] = {0};
  >   // typeName ArName[ArSize] = {elements};
  >
  >   #include <array>
  >   array<int, 5> a = {0};
  >   // array<typeName, ArSize> ArName= {element};
> ```
  > ###### 이외에도 Array 모든 값 출력, 최댓값 출력을 찾아보았다.
  > ### 02-2 Cout a whole array
  > > <a> https://stackoverflow.com/questions/33439064/cout-a-whole-array-in-c
> ```cpp
  >   // without Loop
  >   std::copy(std::begin(arra), 
  >             std::end(arra),
  >             std::ostream_iterator<int>(std::cout, "\n"));
  >   // with Loop
  >   for (const auto& e : arra) {
  >     std::cout << e << std::endl;
  >   }
> ```
  > ###### 아직 동적할당이 익숙하지 않아서, 추후에 볼 필요가 있음.
  >
  > ### 02-3 Max in a C++ Array
  > > <a> https://stackoverflow.com/questions/34315002/max-in-a-c-array
  > ```cpp
  > #include <iostream>
  > #include <algorithm>
  > #include <array>
  > // Example 1
  >  cout << *std::max_element(array, array + n) << "\n";
  > // Example 2
  >  cout<<"Max: "<< *max_element(arr.begin(),arr.end())<<endl;
  > ```
