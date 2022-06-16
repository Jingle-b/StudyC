// 입출력 중 입력 단계 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void main(void) {
	//int a; 
	//int res; //이렇게 선언해야 밑줄오류가 생기지 않는다.
	////res = 1 : 정상적으로 입력 res = 0 : 잘못된 값이 입력되었다.

	//printf("정수를 입력하세요. > "); // 입력할 때 헷갈리지 않기 위함
	//res = scanf("%d", &a); // 콘솔에서 키보드로 입력값을 받음  - 숫자도 입력받을 수 있다.
	////a 변수의 시작 주소!! 
	//printf("입력된 값 :%d\n", a);	//문자열 입력하면 잘못된 값 출력한다. 

	//int age;
	//double height;

	//printf("나이와 키를 입력하세요 > ");
	//res= scanf("%d%lf", &age, &height);	//입력을 다른 자료형으로 하면 res = 0이 된다. (예외사항! 디버깅 과정 중)
	////C는 예외처리가 없기 때문에, 모든 예외를 코드상으로 처리해줘야 한다. 
	//printf("나이는 %d살 키는 %.1lfcm 입니다.", age, height);

	char grade;
	char name[20];
	char res;
	printf("학점 입력 >");
	res = scanf(" %c", &grade);
	printf("이름 입력 > ");
	res = scanf(" %s", name); //문자열에서는 변수명 자체가 변수의 시작 주소를 타나낸다.
	//&안쓰는 이유 = name은 배열이므로, 배열 자체가 배열의 주소 시작을 나타내기 때문에 &빼고 사용 가능
	//포인터 내용! 
	printf("%s 학생의 학점은 %c", name, grade);



}