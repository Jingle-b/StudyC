// 문자열 입력 처리 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//문자열을 처리하기 위한 함수들 

int main(void) {
	char temp[80] ; //사이즈 설정(_MAX_DIR 사용하기도 함 - 256)
	char* str[3]; // 동적으로 계속 보고싶을때 char** str;로 작성한다. 
	int i;

	for (i = 0; i < 3; i++) {
		printf("문자열을 입력하세요 > ");
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1);  //+1 하는 이유 = 마지막 NULL 값(\0)이 필요하기 때문 
		// char * = char 포인터

		strcpy(str[i], temp); // 동적 할당된 사이즈에 temp[80] strcpy(포인터 변수 이름. 포인터 배열의 시작 주소?)

	}
	for (i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	for (i = 0; i < 3; i++) {
		free(str[i]); //동적할당이 3번이라 free도 3번
	}
}

