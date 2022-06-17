#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int res = 1;
	int i = 1;

	while (i < 10) {
		if (i == 5)
			break;  //if문 뒤에 코드가 한 줄일때 -> 중괄호 없이 작성 가능  
		res = res * i;
		i ++;

	}
	printf("%d\n", res);

}