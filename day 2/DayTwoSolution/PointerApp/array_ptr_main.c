#include <stdio.h>

void print_array(int []); //뒤에 매개변수를 넣지 않기 때문에 이와 같이 나타내도 괜찮다, 
// void print_array(int *);와 동일 

int main(void) {
	/* 배열과 포인터의 관계 

	int arr[3]; //사이즈 3의 배열 선언
	
	//배열을 포인터 형태로 쓸 수 있다. 
	*(arr + 0) = 10;
	*(arr + 1) = 20; //array는 int형 -> 4 byte 이동한 주소가 arr +1의 주소
	*(arr + 2) = 30;

	for (int i = 0; i < 3; i++) {
		printf("%d\t", arr[i]);
	}

	*/
	
	int ary[5] = { 10,20,30,40,50 };  //array 초기화 
	print_array(ary);
}

void print_array(int a[]) { //선언한 함수와 괄호 다르게 a다음 [] (array[])
	// void print_array(int *a)와 동일  
	for (int i = 0; i < 5; i++) {
		printf("%d\t", a[i]);  //배열을 만들었지만, 메모리에는 포인터 형식으로 등록되고, 출력할 때 int 출력한다. (관계성!)
	}

}