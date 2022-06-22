#pragma comment (lib, "libmysql.lib")


#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

//MySQL 접속 설정(이후 새로 생성시에 변경 필요!)
#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "bms"
#define loginpassword "1234"
#define mysqlname "bms"

int main(void) {
	MYSQL* conn; //접속객체

	conn = mysql_init(NULL);
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "연결 오류: %s\n", mysql_error(conn));
		return 1;
	}
	else
	{
		printf("연결 성공!\n");
		printf("서버 버전 %s \n", conn->server_version);
	}

	mysql_close(conn);
	return 0;

}


