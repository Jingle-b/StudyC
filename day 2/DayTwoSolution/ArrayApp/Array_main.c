#include <stdio.h>

int main(void) {
	int arr[5] = {0,}; //크기 5짜리 배열 생성  
					   // ={0,} : 모든 값을 0으로 초기화 (모든 배열의 값을 다 채우지 못하더라도 이상한 값이 나오지 않는다. 
	arr[0] = 90; 
	arr[1] = 95; 
	arr[2] = 80; 
	arr[4] = 90;
	printf("네 번째 학생의 점수를 입력하세요: ");
	scanf("%d", &arr[3]);

	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);
	printf("%d\n", arr[3]);
	printf("%d\n", arr[4]); //초기화 안하면 쓰레기값 나온다. 

	int sum = 0; // 변수 초기화
	float average;

	for (int i = 0; i <= 4; i++) {
		sum += arr[i];
	}
	average = sum / 5;

	printf("모든 학생의 점수 총합 :  %d\n",sum );
	printf("평균 점수 : %.1lf\n", average );


}