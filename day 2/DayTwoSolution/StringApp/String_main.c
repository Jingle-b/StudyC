#include <stdio.h>
#include <string.h>

void main(void) {
	
	char str[80]; //str[80]으로 선언하면 값 못받음 //char *str; 로 했더니 오류남
	//str = "apple"; // 직접 못넣는다
	// 배열로 된 것을 포인터로 나타낼 수 있고, 반대로 나타낼 수 도 있으나, 
	// 완전히 둘이 같은 것은 아니기 때문에 아래와 같이 나타내야 한다. 
	strcpy(str, "apple");
	printf("%s\n", str);
		
	strcpy(str, "안녕하세요~");
	printf("%s\n", str);

	/*
	printf("이름을 입력하세요 > ");
	gets(str);
	printf("이름은 %s\n", str);
	*/

	//문자열을 원하는 길이만큼 잘라서 복사하는 기능
	//substring은 제공하지 않음 -> 구현 필요
	char str2[20] = "mango tree";
	strncpy(str2, "apple-pie", 5); //길이만큼 잘라붙여쓰겠다. (strcpy는 전부 같다붙여쓰는것)
	//5를 6으로 바꿔서 테스트 해봄 (6)apple-tree 
	printf("%s\n", str2);

	//문자열 결합함수
	char str3[80] = "straw"; //빨대
	strcat(str3, "berry");
	printf("%s\n", str3);

	strncat(str3, "piece",3); //글자 3개만 떼어서 붙인다. 
	printf("%s\n", str3);


	//문자열 길이를 리턴해주는 함수
	printf("%d\n", strlen(str3)); //null문자 앞까지 길이를 재어준다.

	//문자열 비교함수 
	char str5[80] = "pear"; //112,101,97,114
	char str6[80] = "peach"; //112,101,97,99,104
	
	printf("사전에 나중에 나오는 과일 이름 > "); // strcmp를 통해 어느 문장이 더 뒤에 나올 수 있는지 알 수 있음
	if (strcmp(str5, str6) > 0) {
		printf("%s\n", str5);
	}
	else {
		printf("%s\n", str6);
	}


	printf("사전에 나중에 나오는 과일 이름 > "); // strncmp를 통해 주어진 개수만큼만 글자 비교 후 출력 
	if (strncmp(str5, str6,3) > 0) { 
		printf("%s\n", str5);
	}
	else {
		printf("%s\n", str6); //같아서 0나옴 
	}



}														