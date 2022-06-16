// 문자열 학습 main.c

#define _CRT_SECURE_NO_WARNINGS //속성 통해서 전처리기에 _CRT_SECURE_NO_WARNINGS 입력하는 것과 같은 결과나옴
// strcpy, scanf등 사용할 때 사용되는 전처리기 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void) {

	const double tax_rate = 0.12; //세율 초기화 
	// const = 바꿀 수 없는 값을 설정할 때 사용!
	// tax_rate = 0.15; //l-value가 const 개체를 지정합니다. = 이 값은 바꿀 수 없다 = 상수값은 변경 불가입니다.(error) 

	/*
	char fruit[6] = "사과";
	// apple은 다섯자리인데, 문자열이므로 마지막에 \0(end of string)이 붙어있으므로 다 출력되어야 하기 때문에 6으로 해줘야 하는 것!!
	// 문자열을 담을 때 숫자 = 문자열의 문자 개수 +1
	printf(" %s\n", fruit);
	*/

	int ia;
	//print("%d\n", ia); // 지역변수를 초기화하지 않고 사용할 수 없다. = 쓰레기값있어서 문법적으로 막음
	
	// char fruit[6] = "햇사과"; -> 오류남(모자라서)
	char fruit[7] = "햇사과";
	printf(" %s\n", fruit);
	// fruit = "apple"; 할 수 없음 

	//C언어는 한 번 값을 fix한 경우, 문자열을 바꿀 수 없다. -> 해결법 : string copy = strcpy
	strcpy(fruit, "apple");
	printf("%s\n", fruit);

}
