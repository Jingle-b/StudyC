// calloc, realloc 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi; // 정수형 포인터 
	int size = 5, count = 0, num, i; //한 줄에 나타내기

	// calloc 
	pi = calloc(size, sizeof(int)); //calloc  : malloc과 달리 초기화시켜준다. (0으로!)
	// = 5의 int형  배열 -> 0으로 초기화

	while (1)
	{
		printf("양수만 입력하세요. =>");
		scanf("%d", &num);
		if (num <= 0) break;	//5까지 늘어났으면 종료 
		//5보다 입력할 개수가 늘어나는 경우, 사이즈를 늘려주는 작업
		//realloc 

		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, sizeof(int) * size); //+5 증가 //필요하다면 동적으로 할당하는 메모리를 추가할 수 있다. 
		}


		pi[count] = num;
		count++;
		// pi[count]에 num 값을 넣고, count의 값을 1씩 증가한다.
		// pi[count++] = num  

	}

	for (i = 0; i < size; i++) {
		printf("%5d", pi[i]);
	}

	free(pi);

}

