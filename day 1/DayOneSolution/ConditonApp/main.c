#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	/*
	int a = 10;
	//if문 생략!
	//scanf("%d", &a);
	if (a > 10) {
		printf("a는 10보다 크다");
	}
	else if (a == 10) {
		printf("a는 10이다.");
	}
	else {
		printf("a는 10보다 작다.");
	}
	*/

	char grade;

	printf("학점을 입력하세요 > ");
	scanf("%c", &grade);

	if (grade == 'A') {
		printf("대단하네요!");
	}
	else if (grade == 'B') {
		printf("정말 잘하셨습니다!");
	}
	else if (grade == 'C') {
		printf("잘했습니다.");
	}
	else if (grade == 'D') {
		printf("겨우 통과했군요.");
	}
	else if (grade == 'F') {
		printf("다음 학기에 또 봐요~");
	}
	else {
		printf("학점을 제대로 입력하세요.");
	}

	//모든 if문은 switch문으로 바꿀 수 있다. (반대로도 가능)


	switch (grade)
	{
	case 'A':
		printf("대단하네요!");
		break; //반복문이 아님에도 필수! 
	case 'B':
		printf("정말 잘하셨습니다!");
		break;
	case 'C':
		printf("잘했습니다.");
		break;
	case 'D':
		printf("겨우 통과했군요.");
		break;
	case 'F':
		printf("다음 학기에 또 봐요~");
		break;
	default : //다섯가지 케이스가 아닌 경우
		printf("학점을 제대로 입력하세요.");
		break;
	}
}