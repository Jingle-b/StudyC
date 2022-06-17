#include <stdio.h>

//함수 정의
int sum(int, int); //함수 원형, int sum(int x, int y)로 나타내는게 정석 (코드와 같이 매개변수명 생략해서 나타내도 된다!) 

//메인 함수
int main(void) {
	printf("합산하기 \n");
	
	int total = sum(100, 34);
	printf("합계, %d\n", total);
}

//함수 구현
int sum(int x, int y) {
	int res;
	res = x + y;
	return res;
}