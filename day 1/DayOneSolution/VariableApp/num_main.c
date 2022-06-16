// ���� �н� main.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a;
	int b, c;
	float fa;
	double da;
	char ch; //c���� string�� ����.

	a = 10;
	b = a; c = a + 20;
	fa = 3.5f; //float ���� ���, ���� f�� �ٿ� f�� ���� �Ҵ��Ѵٴ� ǥ���� ��쵵 ����
	// double �� float�� ȥ�� ����
	da = 3.5;
	ch = 'A';

	printf("���� a�� : %d\n", a);
	printf("���� b�� : %d\n", b);
	printf("���� c�� : %d\n", c);
	printf("���� fa�� : %f\n", fa); // f, lf ���� ��� ������ 
	//printf("���� fa�� : %d\n", fa); // ������ �ʿ��� ���, ���޵� ���� �������� ���� �߻� ����(��, ������ �߻� ����)
	printf("���� da�� : %lf\n", da);
	printf("���� ch�� : %c\n", ch);
	printf("���� ch�� : %d\n", ch);  // d(����)�� printf�ϰ� �ؼ�, �ƽ�Ű�ڵ� �� ����
	printf("���� ch�� : %c\n", 97); // ��� ���� �ƽ�Ű�ڵ尡 �ִ�. 

	char kch;
	kch = '��';
	printf("���� kch �� : %c\n", kch); // �ѱ��� �� �ȳ��´�! �ٸ� ����(C#)�� �ѱ� �� �ȴٰ� �Ѵ�.

	short sh = 32767; // -32768 ~ 32767
	int in = 2147483647; 
	long ln = 2147483647;
	long long lln = 9223372036854775807; //ū ���ڵ� ����

	printf("���� sh �� : %d\n", sh); 
	printf("���� in �� : %d\n", in);
	printf("���� ln �� : %ld\n", ln);
	printf("���� lln �� : %lld\n",lln); 

	/*
	short sh = 32767 + 1; //������ �Ѿ�� ���� ǥ���� ���� ���� = overflow 
	int in = 2147483647 + 1;
	long ln = 2147483647 + 1;
	long long lln = 9223372036854775807 + 1; //ū ���ڵ� ����

	printf("���� sh �� : %d\n", sh);
	printf("���� in �� : %d\n", in);
	printf("���� ln �� : %ld\n", ln);
	printf("���� lln �� : %lld\n", lln); 
	*/

	// overflow �����ϱ�! = ���� ���� �� �ִ� �Ѱ谡 �������ִ�. 
	// �� ���� ���ڴ� ū ������ ���� ���� �� ����. 

	//����� ǥ���ؾ� �ϴ� ��� �ڷ��� �Ѱ� 
	//unsigned  = ������ ����
	unsigned short ush = 65535; //�����
	printf("���� ush�� �� : %d\n", ush);

	/*
	unsigned short usha = - 1 ; //���� ���� ��� 
	printf("���� usha�� �� : %d\n", usha);  //��������

	unsigned short ushb = 65535+1; //�����
	printf("���� ushb�� �� : %d\n", ushb);  //0���� 
	*/

	float fv = 1.234567890123456789f;
	double dv = 1.234567890123456789;
	printf("���� fv�� �� : %.20lf\n", fv);
	printf("���� dv�� �� : %.20f\n", dv);

		
		
	return 0;
}
