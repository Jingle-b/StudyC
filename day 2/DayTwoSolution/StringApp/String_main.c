#include <stdio.h>
#include <string.h>

void main(void) {
	
	char str[80]; //str[80]���� �����ϸ� �� ������ //char *str; �� �ߴ��� ������
	//str = "apple"; // ���� ���ִ´�
	// �迭�� �� ���� �����ͷ� ��Ÿ�� �� �ְ�, �ݴ�� ��Ÿ�� �� �� ������, 
	// ������ ���� ���� ���� �ƴϱ� ������ �Ʒ��� ���� ��Ÿ���� �Ѵ�. 
	strcpy(str, "apple");
	printf("%s\n", str);
		
	strcpy(str, "�ȳ��ϼ���~");
	printf("%s\n", str);

	/*
	printf("�̸��� �Է��ϼ��� > ");
	gets(str);
	printf("�̸��� %s\n", str);
	*/

	//���ڿ��� ���ϴ� ���̸�ŭ �߶� �����ϴ� ���
	//substring�� �������� ���� -> ���� �ʿ�
	char str2[20] = "mango tree";
	strncpy(str2, "apple-pie", 5); //���̸�ŭ �߶�ٿ����ڴ�. (strcpy�� ���� ���ٺٿ����°�)
	//5�� 6���� �ٲ㼭 �׽�Ʈ �غ� (6)apple-tree 
	printf("%s\n", str2);

	//���ڿ� �����Լ�
	char str3[80] = "straw"; //����
	strcat(str3, "berry");
	printf("%s\n", str3);

	strncat(str3, "piece",3); //���� 3���� ��� ���δ�. 
	printf("%s\n", str3);


	//���ڿ� ���̸� �������ִ� �Լ�
	printf("%d\n", strlen(str3)); //null���� �ձ��� ���̸� ����ش�.

	//���ڿ� ���Լ� 
	char str5[80] = "pear"; //112,101,97,114
	char str6[80] = "peach"; //112,101,97,99,104
	
	printf("������ ���߿� ������ ���� �̸� > "); // strcmp�� ���� ��� ������ �� �ڿ� ���� �� �ִ��� �� �� ����
	if (strcmp(str5, str6) > 0) {
		printf("%s\n", str5);
	}
	else {
		printf("%s\n", str6);
	}


	printf("������ ���߿� ������ ���� �̸� > "); // strncmp�� ���� �־��� ������ŭ�� ���� �� �� ��� 
	if (strncmp(str5, str6,3) > 0) { 
		printf("%s\n", str5);
	}
	else {
		printf("%s\n", str6); //���Ƽ� 0���� 
	}



}														