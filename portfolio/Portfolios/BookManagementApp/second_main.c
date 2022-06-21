#pragma comment (lib, "libmysql.lib") //My SQL 라이브러리 사용 선언

#include <stdio.h> 
#include <stdlib.h> // 기본
#include <string.h>
#include <Windows.h>
#include <locale.h>

#include <winsock.h>
#include <mysql.h>

#define mysqlip "127.0.0.1" //localhost 의미, 외부 서버에서 한다면 해당 IP 사용
#define port 3306 
#define userid "root"
#define password ""
#define mysqlname "ems" //mysql schema 이름

int main(void) {
	// 1. 준비 과정 
	MYSQL* conn; //connection, MySQL 접속을 위한 MYSQL 구조체 포인터
	MYSQL_RES* result; //response
	MYSQL_ROW row;
	
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;

	int i = 0;
	setlocale(LC_ALL, "Korean"); //한국어 깨짐 방지용

	//MySQL 접속 시작
	conn = mysql_init(NULL) ;  // MySQL 초기화
	mysql_real_connect(conn, mysqlip, userid, password,
						mysqlname, port, NULL, 0); //실제로 접속할 수 있음 

	if (conn == NULL) { //동적 할당을 못받은 경우
		fprintf(stderr, "연결오류 : %s\n", mysql_error(conn));
		return EXIT_FAILURE; 
	}

	printf("연결 성공!\n");
	// TO DO : 연결된 이후 처리!

	printf("서버 버전 %s \n", conn->server_version); //포인터 연결
 
	// 2. 쿼리 실행 
	query_stat = mysql_query(conn, "SELECT * FROM books_info"); //문자열 안에 ; 포함하면 안됨(오류!)
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류 : %s\n", mysql_error(conn));
		mysql_close(conn);
		return EXIT_FAILURE;
	}
	
	// 3. 쿼리 결과를 화면에 출력 
	// my_sql_res 에 있는 데이터 목록들을 넘겨줌
	result = mysql_store_result(conn);  // 결과 정보 객체가 넘어옴 
	
	// 하나씩 분해 
	num_fields = mysql_num_fields(result); // 컬럼 개수
	while (row = mysql_fetch_row(result)) { // fetch_row : 아주 중요!! - 할 때마다 한 줄씩 읽어서 mysql_row를 준다.
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++) {
			printf("[%.*s]", row[i] ? row[i] : "NULL"); // 공백있더라도 한 컬럼에 있는 내용물 전부 출력
			// row[i]가 null이 아니면 출력
		}
		printf("\n");
	} 


	// 연결 풀(Connection Pool) 비워주기 위해, 연결을 끊어준다.
	mysql_close(conn);
	printf("연결 종료\n");

	system("pause");
	return EXIT_SUCCESS; // 0, 1 대신 EXIT_SUCCESS, EXIT_FAILURE

}