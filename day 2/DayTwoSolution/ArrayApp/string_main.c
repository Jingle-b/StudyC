#include <stdio.h>
#include <string.h>

int main(void) {
	//char str[80] = "applejam";
	//printf("���� ���ڿ� : %s\n", str);
	//printf("���ڿ� �Է� >"); 
	//scanf("%s", str); //���ڿ� �迭�� &��������  //���⼭�� �����̽��ٸ� ����Ͽ� �� �� ���, �պκи� ��
	//// \0 = null = ������ �����ٴ� �ǹ� 
	//printf("�Է� ���ڿ� ��� : %s\n", str);
	char str1[80] = "Cat";  //������ ���  
	char str2[80];  //�� ����  

	char* str3 = "Hello World!"; //�� ���� ���
	printf("%s\n", str3);
	
	strcpy(str2, str1); // string copy ���ڿ� ���� �Լ� // ���� : �Ҵ��� ����, ���� 
	printf("%s %s\n", str1, str2); //�������

	printf("���ڿ� �Է� >"); 
	gets(str2); //���� ������ �� ����
	puts("�Է� ���ڿ� :"); //\n �ڵ����� ���־ �˾Ƽ� �� �� ��������
	puts(str2);
	printf("�Է� ���ڿ� : %s \n" ,str2);

	// ��Ȳ�� ���� puts, printf �����ؼ� ����ϱ�  
}