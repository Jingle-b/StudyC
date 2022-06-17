//포인터를 쓰는 이유
#include <stdio.h>

void swap(int*, int*);

int main(void) {
	int a = 33, b = 98;

	printf("스왑 전 a  = %d, b = %d\n", a, b);
	swap(&a, &b); // a와 b의 주소를 넘겨줘서
	printf(" 스왑 후 a = %d. b = %d\n", a, b);
}


void swap(int *x, int *y) {
	int temp; //값이 없음
	temp = *y; //98
	*y = *x; //33
	*x = temp;//98
}