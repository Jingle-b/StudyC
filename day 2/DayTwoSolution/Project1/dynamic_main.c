#include <stdio.h>
#include <stdlib.h>

//���� ������������ �ʾƵ� ���ϴ� �����͸� �޾ƿ� �� �ִ�. 
int main(void) {
	int* pi;
	double* pd;

	pi = malloc(sizeof(int)); //int������(4����Ʈ)�� �޸𸮸� �������� �Ҵ��Ѵ�. 
	
	
	if (pi == NULL) {
		printf("#�޸𸮰� �����մϴ�. \n");
		exit(1); // ������������ ����
	}

	pd = (double*)malloc(sizeof(double)); //malloc = ���̵� ����Ʈ -> double point�� ����ȯ 
	if (pi == NULL) {
		printf("#�޸𸮰� �����մϴ�. \n");
		exit(1); // ������������ ����
	}
	*pi = 10;
	*pd = 3.141592;

	printf("%d\n", *pi);
	printf("%lf\n", *pd);
	//�޸𸮸� �������� �Ҵ��ϰ� �Ǹ�, ����� ������ ������ �Ҵ�ǰ� �ȴ�(����)
	
	//��ó�� //�ʼ�!!
	free(pi); free(pd);  //�����޸� �Ҵ��� ���� 
	

}