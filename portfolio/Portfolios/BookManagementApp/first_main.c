#pragma comment (lib, "libmysql.lib") //My SQL ���̺귯�� ��� ����

#include <stdio.h> 
#include <stdlib.h> // �⺻
#include <WinSock2.h> //DB��, ��Ʈ��ũ ��� 
#include <my_global.h>
#include <mysql.h>

int main(void) {
	printf("MySQL info = %s \n", mysql_get_client_info());
	system("pause");
	return EXIT_SUCCESS; // 0, 1 ��� EXIT_SUCCESS, EXIT_FAILURE

}