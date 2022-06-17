#include <stdio.h>

void print_array(int*, int); //처음 함수를 선언할 때 매개변수를 굳이 적지 않는다. 

int main(void) {

	int ary1[5] = { 10,20,30,40,50 }; // 크기 5의 배열
	int ary2[7] = { 10,20,30,40,50,60,70 }; // 크기 7의 배열

	//printf("%d", sizeof(ary1)); //20 
	//printf("%d", sizeof(ary1[0])); //int의 크기 = 4
	int size = sizeof(ary1) / sizeof(ary1[0]);  //ary1배열 크기/ary1 요소의 크기
	print_array(ary1, size);

	size = sizeof(ary2) / sizeof(ary2[0]);
	print_array(ary2, size);
	
}

void print_array(int* pa, int size) { //포인터 받아서 

	for (int i = 0; i < size; i++) {
		printf("%d\t", pa[i]);  //배열로 사용 (1:1 관계라서 가능)
	}

}