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
