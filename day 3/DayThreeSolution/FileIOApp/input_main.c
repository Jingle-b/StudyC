// ���� �б�
#include <stdio.h>

int main(void) {
	FILE* fp; //����ü(Ŭ�������� �Լ� ���� ������ �ִ� �Ͱ� ������ ����)
	int ch;

	fp = fopen("C:\\Temp\\a.txt", "r"); // a.txt ������ �б� ���� ����
	if (fp == NULL) {
		printf("������ ���� ���߽��ϴ�. \n");
		return 1; // ==exit(1);  //(1= �����ڵ�)
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) break; //EOF = End Of File �� ���� 
	

		putchar(ch); //printf("%c", ch); �� ����
	}

	fclose(fp); // ���� �ݾ���� �Ѵ�!! �ݵ��~~
}
