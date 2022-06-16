#include <stdio.h>

void main(void) {
	int a, b;
	int sum, sub, mul, inv;

	a = 10;
	b = 20;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;
	
	printf("a = %d, b = %d\n", a, b);
	printf("sum = %d\n", sum);
	printf("sub = %d\n", sub);
	printf("mul = %d\n", mul);
	printf("inv = %d\n", inv);

	//나누기
	double apple;
	int banana, orange;

	apple = 5.0 / 2.0;
	banana = 5 / 2; //banana 0과 apple 0.0을 넣으면 error발생 -> 예외처리가 없는 언어이므로!
	orange = 5 % 2;

	printf("apple : %.1lf\n", apple);
	printf("banana : %.d\n", banana);
	printf("orange : %.d\n", orange);

	printf("%d\n", a);
	printf("%d\n", ++a); //[전치] 1증가시키고 출력
	printf("%d\n", a++); //[후치] 출력을 하고 1증가시킴(값에 증가한 값은 할당되었으나, 출력값만 원래값)
	 
	//논리연산 결과, 관계연산 결과가 True False가 없음(파이썬과 달리) - 참이면 1 거짓이면 0 - C++은 있음 
	//l value :변수만 가능 (res에 값 할당할 때) ,r value(이후 다른 함수에 이용될 때)
}