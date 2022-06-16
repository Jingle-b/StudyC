#include <stdio.h>

int main(void) {
	// escape character ���� 
	printf("Be happy\n");
	printf("My\tFriend\n");
	printf("Good\bd\tchance\n");
	printf("Cow\rW\a\n"); // \a = �˸��� 

	// ������ �Ǽ� ȭ�� ���
	printf("%d\n", 10);
	printf("%lf\n", 3.141592); //long float ��� ���� 
	//printf("%d\n", 3.141592); //���� �ƴ� �� ����Ϸ��ٰ� �̻��� ���ڷ� ��� -> �ڷ����� �ȸ¾Ƽ�!  
	printf("%.1lf\n", 3.141592); // .1 = �Ҽ��� ù°�ڸ������� ����϶�
	printf("%.10lf\n", 3.141592); // �Ҽ��� ���ڸ� ����϶�
	//printf("%.10lf\n", 3); //�� �ڷ��� �ȸ¾Ƽ� �̻��ϰ� ����!
	printf("%1f\n", 3.141592);  // �׳� f�� ����ص� ����� �� 
	printf("%d�� %d�� ���� %d�Դϴ�.\n", 10,20,10+20);
	printf("%.1lf - %.1lf = %.1lf\n", 3.4,1.2,3.4-1.2); // �̷� ǥ�����ٴ�, ������ ��Ƽ� ǥ���ϴ� ���� ����
	// ���⼭�� �ڷ��� �ȸ����� �̻��ϰ� ��µȴ�. 


	// ���� ǥ��
	printf("%d\t", 12);	// 12�� 10���� ǥ��
	printf("%d\t", 014); // 12�� 8���� ǥ��
	printf("%d\n", 0xC); // 12�� 16���� ǥ�� - ��ҹ��� ���� X (c C ����) 
	
	// ���� ǥ�� 
	printf("%.2lf\n", 1e6);
	printf("%.7lf\n",3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	//���� ǥ�� 
	printf("%c\n", 'A'); // ���� character
	printf("%s\n", "A"); // ���ڿ� string
	printf("%c�� %s �Դϴ�.", '1', "first"); 	
	return 0;
}