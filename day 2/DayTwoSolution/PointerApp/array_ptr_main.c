#include <stdio.h>

void print_array(int []); //�ڿ� �Ű������� ���� �ʱ� ������ �̿� ���� ��Ÿ���� ������, 
// void print_array(int *);�� ���� 

int main(void) {
	/* �迭�� �������� ���� 

	int arr[3]; //������ 3�� �迭 ����
	
	//�迭�� ������ ���·� �� �� �ִ�. 
	*(arr + 0) = 10;
	*(arr + 1) = 20; //array�� int�� -> 4 byte �̵��� �ּҰ� arr +1�� �ּ�
	*(arr + 2) = 30;

	for (int i = 0; i < 3; i++) {
		printf("%d\t", arr[i]);
	}

	*/
	
	int ary[5] = { 10,20,30,40,50 };  //array �ʱ�ȭ 
	print_array(ary);
}

void print_array(int a[]) { //������ �Լ��� ��ȣ �ٸ��� a���� [] (array[])
	// void print_array(int *a)�� ����  
	for (int i = 0; i < 5; i++) {
		printf("%d\t", a[i]);  //�迭�� ���������, �޸𸮿��� ������ �������� ��ϵǰ�, ����� �� int ����Ѵ�. (���輺!)
	}

}