// 파일 읽기
#include <stdio.h>

int main(void) {
	FILE* fp; //구조체(클래스에서 함수 없이 변수만 있는 것과 유사한 개념)
	int ch;

	fp = fopen("C:\\Temp\\a.txt", "r"); // a.txt 파일을 읽기 모드로 오픈
	if (fp == NULL) {
		printf("파일을 열지 못했습니다. \n");
		return 1; // ==exit(1);  //(1= 상태코드)
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) break; //EOF = End Of File 의 약자 
	

		putchar(ch); //printf("%c", ch); 와 동일
	}

	fclose(fp); // 파일 닫아줘야 한다!! 반드시~~
}
