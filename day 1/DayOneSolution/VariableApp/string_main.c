// ���ڿ� �н� main.c

#define _CRT_SECURE_NO_WARNINGS //�Ӽ� ���ؼ� ��ó���⿡ _CRT_SECURE_NO_WARNINGS �Է��ϴ� �Ͱ� ���� �������
// strcpy, scanf�� ����� �� ���Ǵ� ��ó���� 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void) {

	const double tax_rate = 0.12; //���� �ʱ�ȭ 
	// const = �ٲ� �� ���� ���� ������ �� ���!
	// tax_rate = 0.15; //l-value�� const ��ü�� �����մϴ�. = �� ���� �ٲ� �� ���� = ������� ���� �Ұ��Դϴ�.(error) 

	/*
	char fruit[6] = "���";
	// apple�� �ټ��ڸ��ε�, ���ڿ��̹Ƿ� �������� \0(end of string)�� �پ������Ƿ� �� ��µǾ�� �ϱ� ������ 6���� ����� �ϴ� ��!!
	// ���ڿ��� ���� �� ���� = ���ڿ��� ���� ���� +1
	printf(" %s\n", fruit);
	*/

	int ia;
	//print("%d\n", ia); // ���������� �ʱ�ȭ���� �ʰ� ����� �� ����. = �����Ⱚ�־ ���������� ����
	
	// char fruit[6] = "�޻��"; -> ������(���ڶ�)
	char fruit[7] = "�޻��";
	printf(" %s\n", fruit);
	// fruit = "apple"; �� �� ���� 

	//C���� �� �� ���� fix�� ���, ���ڿ��� �ٲ� �� ����. -> �ذ�� : string copy = strcpy
	strcpy(fruit, "apple");
	printf("%s\n", fruit);

}
