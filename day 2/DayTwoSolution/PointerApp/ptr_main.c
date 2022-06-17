#include <stdio.h>




int main(void) {

	/*
	//이전까지 했던 방식
	int a;
	printf("정수를 입력하세요");
	scanf("%d", &a);	//변수의 주소를 나타냄
	printf("입력된 정수는 %d입니다.\n", a);
	*/


	/*
	int a;
	int *pa; //a를 가리킬 포인터변수 pa 

	pa = &a; //중요! //pa가 담는 것은 주소라는 것을 생각하자

	printf("정수를 입력하세요");
	scanf("%d", pa);	//변수의 주소를 나타냄
	// 같은 결과 나오려면 scanf("%d",&a) 
	printf("입력된 정수는 %d입니다.\n", a); // a의 주소에 있는 것을 입력했으므로, a를 출력하면 입력된 값이 나오는 것,
	*/


	//여러가지 포인터 사용
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb; //선언하는 것 뿐 (밑에서 사용하는 *pt 와 같은 것이 아니다.)
	//포인터 변수 입력할 때는 변수 선언과 초기화를 동시에 하면 안된다. (int *pt = &total쓰면 안된다는 것 - 정확한 룰에 따르면!)
	int* pt;
	
	pt = &total; 

	double* pg;
	pg = &avg; //포인터 의미 잘 이해하기 위해서는 이렇게 작성해버릇 하기 (고급수준으로 익숙해지면 상단 부분처럼)

	pa = &a; pb = &b; 

	*pt = *pa + *pb;
	*pg = *pt / 2.0; //평균

	printf("두 정수의 값 : %d %d \n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.2lf \n", *pg);

}