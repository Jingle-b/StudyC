// ����� �� �Է� �ܰ� 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void main(void) {
	//int a; 
	//int res; //�̷��� �����ؾ� ���ٿ����� ������ �ʴ´�.
	////res = 1 : ���������� �Է� res = 0 : �߸��� ���� �ԷµǾ���.

	//printf("������ �Է��ϼ���. > "); // �Է��� �� �򰥸��� �ʱ� ����
	//res = scanf("%d", &a); // �ֿܼ��� Ű����� �Է°��� ����  - ���ڵ� �Է¹��� �� �ִ�.
	////a ������ ���� �ּ�!! 
	//printf("�Էµ� �� :%d\n", a);	//���ڿ� �Է��ϸ� �߸��� �� ����Ѵ�. 

	//int age;
	//double height;

	//printf("���̿� Ű�� �Է��ϼ��� > ");
	//res= scanf("%d%lf", &age, &height);	//�Է��� �ٸ� �ڷ������� �ϸ� res = 0�� �ȴ�. (���ܻ���! ����� ���� ��)
	////C�� ����ó���� ���� ������, ��� ���ܸ� �ڵ������ ó������� �Ѵ�. 
	//printf("���̴� %d�� Ű�� %.1lfcm �Դϴ�.", age, height);

	char grade;
	char name[20];
	char res;
	printf("���� �Է� >");
	res = scanf(" %c", &grade);
	printf("�̸� �Է� > ");
	res = scanf(" %s", name); //���ڿ������� ������ ��ü�� ������ ���� �ּҸ� Ÿ������.
	//&�Ⱦ��� ���� = name�� �迭�̹Ƿ�, �迭 ��ü�� �迭�� �ּ� ������ ��Ÿ���� ������ &���� ��� ����
	//������ ����! 
	printf("%s �л��� ������ %c", name, grade);



}