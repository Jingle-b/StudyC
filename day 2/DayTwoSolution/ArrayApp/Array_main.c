#include <stdio.h>

int main(void) {
	int arr[5] = {0,}; //ũ�� 5¥�� �迭 ����  
					   // ={0,} : ��� ���� 0���� �ʱ�ȭ (��� �迭�� ���� �� ä���� ���ϴ��� �̻��� ���� ������ �ʴ´�. 
	arr[0] = 90; 
	arr[1] = 95; 
	arr[2] = 80; 
	arr[4] = 90;
	printf("�� ��° �л��� ������ �Է��ϼ���: ");
	scanf("%d", &arr[3]);

	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);
	printf("%d\n", arr[3]);
	printf("%d\n", arr[4]); //�ʱ�ȭ ���ϸ� �����Ⱚ ���´�. 

	int sum = 0; // ���� �ʱ�ȭ
	float average;

	for (int i = 0; i <= 4; i++) {
		sum += arr[i];
	}
	average = sum / 5;

	printf("��� �л��� ���� ���� :  %d\n",sum );
	printf("��� ���� : %.1lf\n", average );


}