// ����  : int main(void) �� �н�
// ���� �ڵ�

#include <stdio.h>
#include <string.h>

//�ֿܼ��� c���α׷� �� ��, ���������� ���̴� ���� ��Ʈ������Ʈ �Լ� ����
int main(int argc, char** argv){
	int i;

	for (i=0;i<argc;i++){
		//  printf("%d��° �μ� %s\n", i, argv[i]);
		if (i == 1) {
			if (strcmp(argv[i], "--version") ==0) { //�����δ� ���ϴ� ������ �� �����ϴ�. 
				printf("DynamicAllopApp version 2.29.1windows.1\n");			
			}
			else if (strcmp(argv[i], "--help") == 0) {
				printf("���� �Դϴ�!! ....\n");
			}
		}
	
	}

	system("pause");

}

