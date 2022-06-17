#include <stdio.h>

int main(void) {
	long double a = 1; //c언어는 데이터 사이즈에 대한 제약이 심하다. -> 주의! 
	
	for (int i = 0; i<3; i++){ //for문 형식(초기값;반복조건;증감연산)
		a = a * 2;
	}
	printf("a = %lld\n", a);

}