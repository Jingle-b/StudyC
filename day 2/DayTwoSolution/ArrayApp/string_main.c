#include <stdio.h>
#include <string.h>

int main(void) {
	//char str[80] = "applejam";
	//printf("최초 문자열 : %s\n", str);
	//printf("문자열 입력 >"); 
	//scanf("%s", str); //문자열 배열은 &생략가능  //여기서는 스페이스바를 사용하여 띄어서 쓸 경우, 앞부분만 들어감
	//// \0 = null = 문장이 끝났다는 의미 
	//printf("입력 문자열 출력 : %s\n", str);
	char str1[80] = "Cat";  //멀쩡히 출력  
	char str2[80];  //儆 나옴  

	char* str3 = "Hello World!"; //더 편한 방법
	printf("%s\n", str3);
	
	strcpy(str2, str1); // string copy 문자열 복사 함수 // 인자 : 할당할 변수, 원본 
	printf("%s %s\n", str1, str2); //정상출력

	printf("문자열 입력 >"); 
	gets(str2); //문장 가져올 때 좋음
	puts("입력 문자열 :"); //\n 자동으로 들어가있어서 알아서 한 줄 내려간다
	puts(str2);
	printf("입력 문자열 : %s \n" ,str2);

	// 상황에 따라 puts, printf 선택해서 사용하기  
}