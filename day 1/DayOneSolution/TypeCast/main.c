#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	printf("%lf\n", (10 + 10.5));
	printf("%lf\n", (float)10); // 10�� long float�� ��� ��� (float)���� (double)�� �־ �ȴ�.
	printf("%d\n", (int)10.5); // �Ǽ��� int�� ��� �� (��, �Ҽ����� ���ư���) ->> ����!!


	int a = 10;
	float fa = 3.4f;
	double da = 3.14;
	printf("int�� ���� ũ�� :%d\n", sizeof(a)); //sizeof = �ǿ����� ũ�⸦ ����Ʈ ������ ����ؼ� �˷���
	printf("float�� ���� ũ�� : %d\n ", sizeof(fa));
	printf("double�� ���� ũ�� : %d\n", sizeof(da));


	//���� ������, *���� ������
	int b = 20, res;
	res = (a > b) ? a : b;
	printf("res �� = %d\n", res);

	//��Ʈ ������  - �̷� ������ ������ �˾Ƶα�
	int c = 10; // 00000000 00000000 00000000 00001010
	int d = 12; // 00000000 00000000 00000000 00001100

	printf("c & d : %d\n", (c & d)); // 8 //�� ��Ʈ�� ��� 1�� �κи� 1�� ��� = &
	// �����̸� &&, ��Ʈ�����̸� & 
	printf("c | d : %d\n", (c | d)); // 14 //�� ��Ʈ�� �ϳ��� 1�� �ڸ��� 1�� ��� = |
	printf("c ^ d : %d\n", (c ^ d)); // 6 //�� ��Ʈ�� ���� �ٸ� ��쿡�� 1�� ��� = ^

	printf("~c : %d\n", ~c);  //�� ��Ʈ�� ��� 1�� �κи� 1�� ��� = &
	printf("c << 1 : %d\n", c << 1); //shift ���� 16+4=20
	printf("c >> 2 : %d\n", c >> 2);	 //32+8 = 40 




}