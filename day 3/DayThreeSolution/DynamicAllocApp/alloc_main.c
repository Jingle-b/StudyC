//#define _CRT_SECURE_NO_WARNINGS //이렇게 해도 되고 속성에서 추가해도 되고

// 배열 동적 할당 
#include <stdio.h>
#include <stdlib.h> //동적할당을 위함


int main(void) {

	int* pi;
	int i = 0, sum = 0;

	// 동적 할당! 
	pi = (int*)malloc(5 * sizeof(int)); // 20바이트 동적할당(malloc) //malloc - void 로 반환
	// 보이드 포인트 = 포인터에서 어떤 것을 받을지 모를때 사용 -> 그래서 이 경우 int로 변환해준다

	if (pi == NULL) { //20바이트 못받았을 때 = 할당한 크기보다 파일이 큰 경우
		printf("메모리가 부족합니다.\n");
			exit(1); //exit(1); = 일반적인 에러 = 
			// 모든 프로그램을 종료할 때 exit(0); -> 이와 같이 exit 내부 들어가는 숫자의 의미가 있다.
			// exit(0) = 성공적으로 프로그램 종료의 의미, 일반적으로 생략한다.
	}

	printf("다섯 명의 나이를 입력하세요.> :");
	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]); //int형 배열 형태로 입력 == &pi[i] 로 표현 가능 
		sum += pi[i]; // *(pi+i) 형태로도 작성 가능(포인터라서) == pi[i] 로 표현 가능 
	}

	printf("다섯 명의 평균 나이 : %.1lf \n", sum / 5.0);

	//malloc 해주면 반드시 free 해줘야 한다.
	free(pi); //동적 메모리 해제, 필수!!



}