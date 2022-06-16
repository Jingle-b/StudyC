#include <stdio.h>

int main(void) {
	// escape character 사용법 
	printf("Be happy\n");
	printf("My\tFriend\n");
	printf("Good\bd\tchance\n");
	printf("Cow\rW\a\n"); // \a = 알림음 

	// 정수와 실수 화면 출력
	printf("%d\n", 10);
	printf("%lf\n", 3.141592); //long float 출력 전용 
	//printf("%d\n", 3.141592); //정수 아닌 것 출력하려다가 이상한 숫자로 출력 -> 자료형과 안맞아서!  
	printf("%.1lf\n", 3.141592); // .1 = 소수점 첫째자리까지만 출력하라
	printf("%.10lf\n", 3.141592); // 소수점 열자리 출력하라
	//printf("%.10lf\n", 3); //또 자료형 안맞아서 이상하게 나옴!
	printf("%1f\n", 3.141592);  // 그냥 f만 사용해도 출력은 됨 
	printf("%d와 %d의 합은 %d입니다.\n", 10,20,10+20);
	printf("%.1lf - %.1lf = %.1lf\n", 3.4,1.2,3.4-1.2); // 이런 표현보다는, 변수에 담아서 표현하는 것이 낫다
	// 여기서도 자료형 안맞으면 이상하게 출력된다. 


	// 진수 표현
	printf("%d\t", 12);	// 12의 10진수 표현
	printf("%d\t", 014); // 12의 8진수 표현
	printf("%d\n", 0xC); // 12의 16진수 표현 - 대소문자 구분 X (c C 동일) 
	
	// 지수 표현 
	printf("%.2lf\n", 1e6);
	printf("%.7lf\n",3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	//문자 표현 
	printf("%c\n", 'A'); // 문자 character
	printf("%s\n", "A"); // 문자열 string
	printf("%c는 %s 입니다.", '1', "first"); 	
	return 0;
}