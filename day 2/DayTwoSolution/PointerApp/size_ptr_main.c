#include <stdio.h>

int main(void) {

	char ch;
	int in;
	double db;

	char* pc;
	pc = &ch;
	int* pi;
	pi = &in;
	double* pd;
	pd = &db;

	printf("�Ϲ� ������ ũ��\n");
	printf("size of char var %d\n", sizeof(ch));
	printf("size of int var %d\n", sizeof(in));
	printf("size of double var %d\n", sizeof(db));

	printf("������ ������ ũ��");
	printf("size of char pointer var %d\n", sizeof(pc)); //&, *�� ���� �׽�Ʈ �ʿ�
	printf("size of int pointer var %d\n", sizeof(pi));
	printf("size of double var %d\n", sizeof(pd));


}