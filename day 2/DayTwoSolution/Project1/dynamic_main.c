#include <stdio.h>
#include <stdlib.h>

//따로 변수생성하지 않아도 원하는 데이터를 받아올 수 있다. 
int main(void) {
	int* pi;
	double* pd;

	pi = malloc(sizeof(int)); //int사이즈(4바이트)로 메모리를 동적으로 할당한다. 
	
	
	if (pi == NULL) {
		printf("#메모리가 부족합니다. \n");
		exit(1); // 비정상적으로 종료
	}

	pd = (double*)malloc(sizeof(double)); //malloc = 보이드 포인트 -> double point로 형변환 
	if (pi == NULL) {
		printf("#메모리가 부족합니다. \n");
		exit(1); // 비정상적으로 종료
	}
	*pi = 10;
	*pd = 3.141592;

	printf("%d\n", *pi);
	printf("%lf\n", *pd);
	//메모리를 동적으로 할당하게 되면, 재부팅 전까지 공간이 할당되게 된다(문제)
	
	//대처법 //필수!!
	free(pi); free(pd);  //동적메모리 할당을 해제 
	

}