// 변수 학습 main.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a;
	int b, c;
	float fa;
	double da;
	char ch; //c언어에는 string이 없다.

	a = 10;
	b = a; c = a + 20;
	fa = 3.5f; //float 값의 경우, 끝에 f을 붙여 f의 값을 할당한다는 표현의 경우도 있음
	// double 과 float의 혼동 방지
	da = 3.5;
	ch = 'A';

	printf("변수 a값 : %d\n", a);
	printf("변수 b값 : %d\n", b);
	printf("변수 c값 : %d\n", c);
	printf("변수 fa값 : %f\n", fa); // f, lf 같은 결과 나왔음 
	//printf("변수 fa값 : %d\n", fa); // 정수가 필요한 경우, 전달된 값이 비정수면 문제 발생 가능(단, 오류는 발생 안함)
	printf("변수 da값 : %lf\n", da);
	printf("변수 ch값 : %c\n", ch);
	printf("변수 ch값 : %d\n", ch);  // d(정수)로 printf하게 해서, 아스키코드 값 나옴
	printf("변수 ch값 : %c\n", 97); // 모든 수는 아스키코드가 있다. 

	char kch;
	kch = '한';
	printf("변수 kch 값 : %c\n", kch); // 한글은 잘 안나온다! 다른 언어에서(C#)는 한글 잘 된다고 한다.

	short sh = 32767; // -32768 ~ 32767
	int in = 2147483647; 
	long ln = 2147483647;
	long long lln = 9223372036854775807; //큰 숫자도 가능

	printf("변수 sh 값 : %d\n", sh); 
	printf("변수 in 값 : %d\n", in);
	printf("변수 ln 값 : %ld\n", ln);
	printf("변수 lln 값 : %lld\n",lln); 

	/*
	short sh = 32767 + 1; //범위를 넘어가는 수를 표현할 수는 없음 = overflow 
	int in = 2147483647 + 1;
	long ln = 2147483647 + 1;
	long long lln = 9223372036854775807 + 1; //큰 숫자도 가능

	printf("변수 sh 값 : %d\n", sh);
	printf("변수 in 값 : %d\n", in);
	printf("변수 ln 값 : %ld\n", ln);
	printf("변수 lln 값 : %lld\n", lln); 
	*/

	// overflow 조심하기! = 값을 담을 수 있는 한계가 정해져있다. 
	// 더 작은 상자는 큰 상자의 값을 담을 수 없다. 

	//양수만 표현해야 하는 경우 자료형 한계 
	//unsigned  = 음수가 없는
	unsigned short ush = 65535; //양수만
	printf("변수 ush의 값 : %d\n", ush);

	/*
	unsigned short usha = - 1 ; //음수 넣은 경우 
	printf("변수 usha의 값 : %d\n", usha);  //오류나옴

	unsigned short ushb = 65535+1; //양수만
	printf("변수 ushb의 값 : %d\n", ushb);  //0나옴 
	*/

	float fv = 1.234567890123456789f;
	double dv = 1.234567890123456789;
	printf("변수 fv의 값 : %.20lf\n", fv);
	printf("변수 dv의 값 : %.20f\n", dv);

		
		
	return 0;
}
