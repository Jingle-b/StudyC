// 기존  : int main(void) 로 학습
// 실제 코드

#include <stdio.h>
#include <string.h>

//콘솔에서 c프로그램 할 때, 실제적으로 쓰이는 메인 엔트리포인트 함수 원형
int main(int argc, char** argv){
	int i;

	for (i=0;i<argc;i++){
		//  printf("%d번째 인수 %s\n", i, argv[i]);
		if (i == 1) {
			if (strcmp(argv[i], "--version") ==0) { //실제로는 비교하는 과정이 더 복잡하다. 
				printf("DynamicAllopApp version 2.29.1windows.1\n");			
			}
			else if (strcmp(argv[i], "--help") == 0) {
				printf("도움말 입니다!! ....\n");
			}
		}
	
	}

	system("pause");

}

