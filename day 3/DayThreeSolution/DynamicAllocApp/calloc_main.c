// calloc, realloc 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi; // ������ ������ 
	int size = 5, count = 0, num, i; //�� �ٿ� ��Ÿ����

	// calloc 
	pi = calloc(size, sizeof(int)); //calloc  : malloc�� �޸� �ʱ�ȭ�����ش�. (0����!)
	// = 5�� int��  �迭 -> 0���� �ʱ�ȭ

	while (1)
	{
		printf("����� �Է��ϼ���. =>");
		scanf("%d", &num);
		if (num <= 0) break;	//5���� �þ���� ���� 
		//5���� �Է��� ������ �þ�� ���, ����� �÷��ִ� �۾�
		//realloc 

		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, sizeof(int) * size); //+5 ���� //�ʿ��ϴٸ� �������� �Ҵ��ϴ� �޸𸮸� �߰��� �� �ִ�. 
		}


		pi[count] = num;
		count++;
		// pi[count]�� num ���� �ְ�, count�� ���� 1�� �����Ѵ�.
		// pi[count++] = num  

	}

	for (i = 0; i < size; i++) {
		printf("%5d", pi[i]);
	}

	free(pi);

}

