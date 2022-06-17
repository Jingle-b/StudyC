#include <stdio.h>

int main(void) {
	int a = 10, b = 20;
	const int* pa; //지정받은 값 외에 다른 값을 다시 지정받을 수 없음(변경불가)
	
	pa = &a;
	printf("a의 값 %d\n", *pa);

	pa = &b;
	printf("b의 값 %d\n", *pa);
	b = 30;
	printf("b의 값 %d\n", *pa);

	//*pa = 40; // error = 빌드 오류 = const 포인터는 변경 불가! = const에 따라, 이미 지정한 값을 변경할 수 없음



	
}