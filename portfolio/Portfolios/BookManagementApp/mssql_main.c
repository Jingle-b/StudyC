#include <wtypes.h>
#include <stdio.h>
#include <string.h>
#include <sql.h>  //�⺻������ ����
#include <sqlext.h>

SQLHENV henv = NULL;	// DB ȯ���� ���� ����ü
SQLHDBC hdbc = NULL;	// DB ������ ���� ����ü

//ODBC�� DB���� 

int ODBCConnect(SQLCHAR* dsn, SQLCHAR* userid, SQLCHAR* pwd){ //SQLCHAR = �ڷ���
	SQLRETURN res;
	henv = NULL;
	hdbc = NULL; //�ʱ�ȭ

	// SQL ȯ�� henv ���� �Ҵ� 
	res = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);  // ������ ������ ���� ȯ�� �Ҵ� 
	if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO ) { //�������� ���� �޼���
		// ODBC ������ ���� ȯ�� �Ӽ� ����
		res = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0); // �̷��� �Է����� �� ��������� ǥ���� ���ڵ� - SQL�� �ִ� ������!
		if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
		// Ŀ�ؼ� �ڵ� ����
			res = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
			if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
				// �����ϱ� ���� ���� ����
				SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)10, 0);
				//���� ����(�߿�!!)
				res = SQLConnect(hdbc, dsn, SQL_NTS, userid, SQL_NTS, pwd, SQL_NTS);
				if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
					return 1; //���Ӽ��� true
				}
				SQLDisconnect(hdbc);
			}
			SQLFreeHandle(SQL_HANDLE_DBC , hdbc);
			hdbc = henv = NULL;
			return 0; //���ӽ��� false 
		}
	}

}

// DB ���� ����
int ODBCDisconnect() {
	if (hdbc) {
		SQLDisconnect(hdbc); //��������
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc); //�ڵ� ��ü�� �����ͷ� �Ǿ��־ ����
	}
	if (henv) SQLFreeHandle(SQL_HANDLE_ENV, henv);
	hdbc = henv = NULL;
	return 1;
}


// ������ �������� 
int db_fetch() {
	// query�� ���� ������
	SQLRETURN rt;
	SQLHSTMT hstmt;
	SQLCHAR sql[256];
	SQLLEN n;

	// query�κ��� ���� �����͸� ������� ����
	SQLINTEGER id;
	SQLCHAR title[100];
	SQLCHAR writer[100];
	SQLCHAR genre[45];
	SQLDATE release_Date;
	SQLSMALLINT pages;
	SQLCHAR company[50];
	SQLDECIMAL price;

	if (hdbc == NULL || henv == NULL) return 0; //false �ǹ�

	rt = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (!(rt == SQL_SUCCESS || rt == SQL_SUCCESS_WITH_INFO))  return 0;

	strcpy(sql, "SELECT id, title, writer, genre, release_date, pages, company, price FROM books_info");
	rt = SQLExecDirect(hstmt, sql, SQL_NTS);
	if (rt != SQL_SUCCESS) {
		printf("cannot access query\n");
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return 0;
	}

	while (1) {
		rt = SQLFetch(hstmt);
		if (rt == SQL_SUCCESS || rt == SQL_SUCCESS_WITH_INFO) {
			rt = SQLGetData(hstmt, 1, SQL_C_ULONG, &id, 0, &n); // �ּҸ� ������ ���� �̿� ���� ǥ��
			rt = SQLGetData(hstmt, 2, SQL_C_WCHAR, title,100, &n); // title = �����Ͷ� �̹� �ּ�

			printf("%d, %s\n", id, title);
		}
		else if (rt == SQL_NO_DATA) {
			printf("no data");
			break;
		}
		else {
			printf("Fail to fetch data!");
			break;
		}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return 1;
	}
}

	

int main(void) {
	int ret = 0;
	printf("MSSQL ���� ����\n");

	ret = ODBCConnect("BMS", "sa", "1234"); 
	if (ret == 1)
		printf("���� ����!\n");

	ret = db_fetch();
	if (ret == 1)
		printf("\n");

	ret = ODBCDisconnect();		//������ �Ǹ� �ݵ�� ����� �Ѵ�. 
	if (ret == 1)
		printf("���� ����!\n");

	return 0;
}