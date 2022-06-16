#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	printf("%lf\n", (10 + 10.5));
	printf("%lf\n", (float)10); // 10을 long float에 담는 방법 (float)말고도 (double)을 넣어도 된다.
	printf("%d\n", (int)10.5); // 실수를 int에 담는 법 (단, 소수점이 날아간다) ->> 주의!!


	int a = 10;
	float fa = 3.4f;
	double da = 3.14;
	printf("int형 변수 크기 :%d\n", sizeof(a)); //sizeof = 피연산자 크기를 바이트 단위로 계산해서 알려줌
	printf("float형 변수 크기 : %d\n ", sizeof(fa));
	printf("double형 변수 크기 : %d\n", sizeof(da));


	//조건 연산자, *삼항 연산자
	int b = 20, res;
	res = (a > b) ? a : b;
	printf("res 값 = %d\n", res);

	//비트 연산자  - 이런 연산이 있음을 알아두기
	int c = 10; // 00000000 00000000 00000000 00001010
	int d = 12; // 00000000 00000000 00000000 00001100

	printf("c & d : %d\n", (c & d)); // 8 //두 비트가 모두 1인 부분만 1로 계산 = &
	// 조건이면 &&, 비트연산이면 & 
	printf("c | d : %d\n", (c | d)); // 14 //두 비트가 하나라도 1인 자리는 1로 계산 = |
	printf("c ^ d : %d\n", (c ^ d)); // 6 //두 비트가 서로 다른 경우에만 1로 계산 = ^

	printf("~c : %d\n", ~c);  //두 비트가 모두 1인 부분만 1로 계산 = &
	printf("c << 1 : %d\n", c << 1); //shift 연산 16+4=20
	printf("c >> 2 : %d\n", c >> 2);	 //32+8 = 40 




}