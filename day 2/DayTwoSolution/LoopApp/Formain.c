#include <stdio.h>

int main(void) {
	long double a = 1; //c���� ������ ����� ���� ������ ���ϴ�. -> ����! 
	
	for (int i = 0; i<3; i++){ //for�� ����(�ʱⰪ;�ݺ�����;��������)
		a = a * 2;
	}
	printf("a = %lld\n", a);

}