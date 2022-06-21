#pragma comment (lib, "libmysql.lib") //My SQL ���̺귯�� ��� ����

#include <stdio.h> 
#include <stdlib.h> // �⺻
#include <string.h>
#include <Windows.h>
#include <locale.h>

#include <winsock.h>
#include <mysql.h>

#define mysqlip "127.0.0.1" //localhost �ǹ�, �ܺ� �������� �Ѵٸ� �ش� IP ���
#define port 3306 
#define userid "root"
#define password ""
#define mysqlname "ems" //mysql schema �̸�

int main(void) {
	// 1. �غ� ���� 
	MYSQL* conn; //connection, MySQL ������ ���� MYSQL ����ü ������
	MYSQL_RES* result; //response
	MYSQL_ROW row;
	
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;

	int i = 0;
	setlocale(LC_ALL, "Korean"); //�ѱ��� ���� ������

	//MySQL ���� ����
	conn = mysql_init(NULL) ;  // MySQL �ʱ�ȭ
	mysql_real_connect(conn, mysqlip, userid, password,
						mysqlname, port, NULL, 0); //������ ������ �� ���� 

	if (conn == NULL) { //���� �Ҵ��� ������ ���
		fprintf(stderr, "������� : %s\n", mysql_error(conn));
		return EXIT_FAILURE; 
	}

	printf("���� ����!\n");
	// TO DO : ����� ���� ó��!

	printf("���� ���� %s \n", conn->server_version); //������ ����
 
	// 2. ���� ���� 
	query_stat = mysql_query(conn, "SELECT * FROM books_info"); //���ڿ� �ȿ� ; �����ϸ� �ȵ�(����!)
	if (query_stat != 0) {
		fprintf(stderr, "�������� : %s\n", mysql_error(conn));
		mysql_close(conn);
		return EXIT_FAILURE;
	}
	
	// 3. ���� ����� ȭ�鿡 ��� 
	// my_sql_res �� �ִ� ������ ��ϵ��� �Ѱ���
	result = mysql_store_result(conn);  // ��� ���� ��ü�� �Ѿ�� 
	
	// �ϳ��� ���� 
	num_fields = mysql_num_fields(result); // �÷� ����
	while (row = mysql_fetch_row(result)) { // fetch_row : ���� �߿�!! - �� ������ �� �پ� �о mysql_row�� �ش�.
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++) {
			printf("[%.*s]", row[i] ? row[i] : "NULL"); // �����ִ��� �� �÷��� �ִ� ���빰 ���� ���
			// row[i]�� null�� �ƴϸ� ���
		}
		printf("\n");
	} 


	// ���� Ǯ(Connection Pool) ����ֱ� ����, ������ �����ش�.
	mysql_close(conn);
	printf("���� ����\n");

	system("pause");
	return EXIT_SUCCESS; // 0, 1 ��� EXIT_SUCCESS, EXIT_FAILURE

}