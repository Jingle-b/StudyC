#include <wtypes.h>
#include <stdio.h>
#include <string.h>
#include <sql.h>  //기본적으로 있음
#include <sqlext.h>

SQLHENV henv = NULL;	// DB 환경을 위한 구조체
SQLHDBC hdbc = NULL;	// DB 접속을 위한 구조체

//ODBC로 DB접속 

int ODBCConnect(SQLCHAR* dsn, SQLCHAR* userid, SQLCHAR* pwd){ //SQLCHAR = 자료형
	SQLRETURN res;
	henv = NULL;
	hdbc = NULL; //초기화

	// SQL 환경 henv 값을 할당 
	res = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);  // 동적인 저장을 위한 환경 할당 
	if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO ) { //성공했을 때만 메세지
		// ODBC 버전에 따른 환경 속성 설정
		res = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0); // 이렇게 입력했을 때 보라색으로 표현된 글자들 - SQL에 있는 값들임!
		if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
		// 커넥션 핸들 설정
			res = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
			if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
				// 접속하기 위한 설정 먼저
				SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)10, 0);
				//실제 접속(중요!!)
				res = SQLConnect(hdbc, dsn, SQL_NTS, userid, SQL_NTS, pwd, SQL_NTS);
				if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
					return 1; //접속성공 true
				}
				SQLDisconnect(hdbc);
			}
			SQLFreeHandle(SQL_HANDLE_DBC , hdbc);
			hdbc = henv = NULL;
			return 0; //접속실패 false 
		}
	}

}

// DB 접속 해제
int ODBCDisconnect() {
	if (hdbc) {
		SQLDisconnect(hdbc); //접속종료
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc); //핸들 자체가 포인터로 되어있어서 가능
	}
	if (henv) SQLFreeHandle(SQL_HANDLE_ENV, henv);
	hdbc = henv = NULL;
	return 1;
}


// 데이터 가져오기 
int db_fetch() {
	// query를 위한 변수들
	SQLRETURN rt;
	SQLHSTMT hstmt;
	SQLCHAR sql[256];
	SQLLEN n;

	// query로부터 얻을 데이터를 담기위한 변수
	SQLINTEGER id;
	SQLCHAR title[100];
	SQLCHAR writer[100];
	SQLCHAR genre[45];
	SQLDATE release_Date;
	SQLSMALLINT pages;
	SQLCHAR company[50];
	SQLDECIMAL price;

	if (hdbc == NULL || henv == NULL) return 0; //false 의미

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
			rt = SQLGetData(hstmt, 1, SQL_C_ULONG, &id, 0, &n); // 주소를 보내기 위해 이와 같이 표현
			rt = SQLGetData(hstmt, 2, SQL_C_WCHAR, title,100, &n); // title = 포인터라서 이미 주소

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
	printf("MSSQL 접속 시작\n");

	ret = ODBCConnect("BMS", "sa", "1234"); 
	if (ret == 1)
		printf("접속 성공!\n");

	ret = db_fetch();
	if (ret == 1)
		printf("\n");

	ret = ODBCDisconnect();		//연결이 되면 반드시 끊어야 한다. 
	if (ret == 1)
		printf("접속 종료!\n");

	return 0;
}