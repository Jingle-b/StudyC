#include <stdio.h>

void main(void) {
	int a, b;
	int sum, sub, mul, inv;

	a = 10;
	b = 20;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;
	
	printf("a = %d, b = %d\n", a, b);
	printf("sum = %d\n", sum);
	printf("sub = %d\n", sub);
	printf("mul = %d\n", mul);
	printf("inv = %d\n", inv);

	//������
	double apple;
	int banana, orange;

	apple = 5.0 / 2.0;
	banana = 5 / 2; //banana 0�� apple 0.0�� ������ error�߻� -> ����ó���� ���� ����̹Ƿ�!
	orange = 5 % 2;

	printf("apple : %.1lf\n", apple);
	printf("banana : %.d\n", banana);
	printf("orange : %.d\n", orange);

	printf("%d\n", a);
	printf("%d\n", ++a); //[��ġ] 1������Ű�� ���
	printf("%d\n", a++); //[��ġ] ����� �ϰ� 1������Ŵ(���� ������ ���� �Ҵ�Ǿ�����, ��°��� ������)
	 
	//������ ���, ���迬�� ����� True False�� ����(���̽�� �޸�) - ���̸� 1 �����̸� 0 - C++�� ���� 
	//l value :������ ���� (res�� �� �Ҵ��� ��) ,r value(���� �ٸ� �Լ��� �̿�� ��)
}