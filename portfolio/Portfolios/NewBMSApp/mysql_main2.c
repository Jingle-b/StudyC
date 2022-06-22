#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

//MySQL 접속 설정(이후 새로 생성시에 변경 필요!)
#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "bms"
#define loginpassword "1234"
#define mysqlname "bms"

#define TITLE_LENGTH 100

//step 3. 지역변수를 전역변수로 전환
//step 4. 다시 지역변수로 전환

// 책 정보를 담을 구조체 bookInfo 생성 
typedef struct bookInfo {	//typedef : 구조체를 만들어서 같이 타입을 변환하고 싶을 때 
	int id;
	char title[TITLE_LENGTH]; // 책 제목
	char writer[TITLE_LENGTH];
	char genre[45];
	char release_date[11]; // release_date를 10으로 할 경우, 오류 위험 
	// 이유 : 2020-06-22 라 할 경우, 딱 10개가 들어간다. -> 사이즈가 11이어야 \0 까지 포함되므로, 오류 방지 가능
	short pages; // small int 
	char company[50];
	int price; // short int라 하기에는 큰 수가 가능하다. 

}book;

//함수 원형 선언
void connect_db(MYSQL*);
void close_db(MYSQL*);
int insert_book(MYSQL*);
int display_books(MYSQL*);
int update_book(MYSQL*);	// mysql 에서 포인터를 받아야 하고, book포인터로 준다
int delete_book(MYSQL*);
int search_book(MYSQL*);
void print_header(void);


int main(void) {

	MYSQL* conn;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	int input = 0; //메뉴 입력값 저장
	int ret = 0; // 리턴 값을 받는 변수
	conn = mysql_init(NULL);
	connect_db(conn);
	
	//무한루프
	while (1) {
		system("cls"); //화면 클리어
		printf("도서 관리 프로그램(v2.0) \n");
		printf("1. 도서 정보 조회\n");
		printf("2. 도서 정보 입력\n");
		printf("3. 도서 정보 수정\n");
		printf("4. 도서 검색\n");
		printf("5. 도서 삭제\n");
		printf("6. 프로그램 종료\n");
		printf("입력 ");
		scanf("%d", &input); rewind(stdin);
	
		switch (input) { //source에서 insert, search, update에서 book포인터 사용 안했음(여기서) -> 삭제하기
		case 1 : 
			ret = display_books(conn);
			if (ret == 100) {
				close_db(conn);
				printf("비정상적으로 종료되었습니다.");
				exit(1); //프로그램 종료
			}
			system("pause");
			break;
		case 2 :
			ret =  insert_book(conn);
			if (ret == 100) {
				close_db(conn);
				printf("비정상적으로 종료되었습니다.");
				exit(1); //프로그램 종료
			}
			system("pause");
			break;
		case 3 :
			ret = update_book(conn);
			if (ret == 100) {
				close_db(conn);
				printf("비정상적으로 종료되었습니다.");
				exit(1); //프로그램 종료
			}
			system("pause");
			break;
		case 4 :
			ret = search_book(conn);
			if (ret == 100) {
				close_db(conn);
				printf("비정상적으로 종료되었습니다.");
				exit(1); //프로그램 종료
			}
			system("pause");
			break;
		case 5 :
			ret = delete_book(conn);
			if (ret == 100) {
				close_db(conn);
				printf("비정상적으로 종료되었습니다.");
				exit(1); //프로그램 종료
			}
			system("pause");
			break;
		case 6 : 
		default: 
			close_db(conn);
			printf("프로그램 종료.");
			printf("이용해 주셔서 감사합니다.");
			exit(0);
			
		}
	}

	close_db(conn);

	/* 초기 코드
	
	int i = 0;

	// 이 경우, 해당 코드로 실행했을 때 한글이 깨져서 출력되지 않는다면 mysql 옵션을 추가해야한다. 
	// mysql_options(conn, MYSQL_SET_CHARSET_NAME, "euckr");
	// mysql_options(conn, MYSQL_INIT_COMMAND, "SETS NAMES euckr");

	conn = mysql_init(NULL);
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "연결오류! : %s\n", mysql_error(conn));
		return 1;
	}

	printf("연결성공!\n");


	query_stat = mysql_query(conn, "SELECT * FROM books_info"); 
	if (query_stat != 0) {	//결과가 0이다 = 오류가 없다. 0이 아니다 = 오류가 있다. 
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return 1;
	}

	result = mysql_store_result(conn);
	num_fields = mysql_num_fields(result);	// 8 
	while (row = mysql_fetch_row(result)) {	// 행의 개수만큼 반복하여 출력한다 
		lengths = mysql_fetch_lengths(result);	
		for (i = 0; i < num_fields; i++)	// 열의 개수만큼 반복하여 출력
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}	// %s라 작성할 경우, 출력이 잘 되긴 하지만, 숫자가 섞였을 때 결과가 제대로 나오지 않는다. 
			// 숫자가 섞인 경우를 대비하여 이와 같이 작성하는 것. [format string part]
			// 공백을 통해, 한 칸 씩 떨어져서 결과를 출력한다.
		printf("\n");
	}

	mysql_close(conn);
	printf("연결종료\n");
	*/
	return 0;

}

void connect_db(MYSQL* conn) {
	
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "연결오류! : %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}
	printf("연결 성공!\n");
}

void close_db(MYSQL* conn) {
	mysql_close(conn);
	printf("연결종료\n");
}

int display_books(MYSQL* conn) {
	MYSQL_ROW row;
	MYSQL_RES* result;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;

	int i = 0;

	query_stat = mysql_query(conn, "SELECT * FROM books_info");
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		// mysql_close(conn);
		return 100; //에러 
	}

	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("출력할 데이터가 없습니다.\n");
		return 0;
	}

	//헤더 
	print_header();

	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	return 0;
}

int insert_book(MYSQL* conn) { // 중요!
	//book insBook = { 0, }; // 구조체를 선언하고 , 초기화함 
	int i, j = 0;
	char query[500] = { 0, };
	book tmpBook = {0,};
	int res = 0;


	printf("책 이름 입력 (필수) > ");
	res = scanf("%[^\n]s", tmpBook.title); // 정규식 %[] 구조체 멤버로 변수를 나타내는거라 insBook ->title 사용
	rewind(stdin); // 표준 입력 refresh

	if (strlen(tmpBook.title) == 0) {
		printf("책 이름이 입력되지 않았습니다.\n");
		printf("메뉴를 종료합니다 \n");
		return 0;
	}

	printf("저자명 입력 (필수) > ");
	res = scanf("%[^\n]s", tmpBook.writer);
	rewind(stdin);
	if (strlen(tmpBook.writer) == 0) {
		printf("저자명이 입력되지 않았습니다.\n");
		printf("메뉴를 종료합니다 \n");
		return 0;
	}

	printf("장르 입력 > ");
	scanf("%[^\n]s", tmpBook.genre);
	rewind(stdin);

	printf("출판일 입력(ex. 2022-06-01) > ");
	scanf("%s", tmpBook.release_date);
	rewind(stdin);

	printf("페이지 수 입력(ex. 300) > ");
	scanf("%d", &tmpBook.pages); //숫자형이라서 &필수 
	rewind(stdin);

	printf("회사명 입력 > ");
	scanf("%[^\n]s", tmpBook.company);
	rewind(stdin);

	printf("가격 입력(ex. 15000) > ");
	scanf("%d", &tmpBook.price); //숫자형이라서 &필수 
	rewind(stdin);

	sprintf(query,  " INSERT INTO books_info " //query 문자열 넣을 때, 반드시 앞 뒤에 공백을 넣어줘야 한다. 
					" (title, writer, genre, release_date, pages, company, price) "
					" VALUES "
					" ('%s' , '%s' , '%s' , '%s' , %d , '%s' , %d ) ",
			tmpBook.title, tmpBook.writer, tmpBook.genre,tmpBook.release_date,
			tmpBook.pages, tmpBook.company, tmpBook.price);

	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "입력 오류 : %s \n", mysql_error(conn)); 
		return 100; // 100 = DB 에러
	}

	printf("책 정보가 입력되었습니다.");
	return 0;
}


//책정보 수정 함수 
int update_book(MYSQL* conn) {
	int  i = 0;
	MYSQL_ROW row;
	MYSQL_RES* result;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	char query[500] = { 0, };

	book tmpBook = { 0, }; //입력받을 임시 변수 생성

	printf("수정할 책 번호 입력 > ");	// ID는 바꾸는 대상이 아님
	scanf("%d", &tmpBook.id); rewind(stdin);

	sprintf(query, "SELECT * FROM books_info WHERE id = %d", tmpBook.id);
	query_stat = mysql_query(conn, query);

	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return 100;
	}

	printf("기존 정보\n");
	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("수정할 데이터가 없습니다.\n");
		return 0;
	}
	

	//헤더 
	print_header();

	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}


	printf("변경 책 이름 입력 > ");
	scanf("%[^\n]s", tmpBook.title);
	rewind(stdin);


	printf("변경 저자명 입력 > ");
	scanf("%[^\n]s", tmpBook.writer);
	rewind(stdin);

	printf("장르 입력 > ");
	scanf("%[^\n]s", tmpBook.genre);
	rewind(stdin);

	sprintf(query, 
		" UPDATE books_info SET "
		"	  title = '%s' 		"
		"	, writer = '%s'		"
		"	, genre = '%s'		"
		"	WHERE id = %d	",
		tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.id);
		
	if (mysql_query(conn, query) != 0) { //오류
		fprintf(stderr, "수정 쿼리 오류! : %s\n", mysql_error(conn));
		return; //수정 쿼리 오류가 될 경우 바꿔줘야함
	}

	printf("책 정보가 수정되었습니다.");

	return 0;

}

//책정보 삭제 함수
int delete_book(MYSQL* conn) {
	MYSQL_ROW row;
	MYSQL_RES* result;
	int query_stat;
	unsigned long* lengths;
	char query[500] = { 0, };
	book tmpBook = { 0, }; //입력받을 임시 변수 생성

	printf("삭제할 책 번호 입력 > ");	// ID는 바꾸는 대상이 아님
	scanf("%d", &tmpBook.id); rewind(stdin);  //scanf와 rewind는 항상 같이 있으므로, 한 줄에 나타내어도 독해 문제 X
	sprintf(query, "SELECT * FROM books_info WHERE id = %d", tmpBook.id);
	query_stat = mysql_query(conn, query);
	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("삭제할 데이터가 없습니다.\n");
		return 0;
	}



	if (mysql_query(conn, query) != 0) { //오류
		fprintf(stderr, "삭제 쿼리 오류! : %s\n", mysql_error(conn));
		return 100;
	}




	sprintf(query, 
		" DELETE FROM books_info WHERE id = %d	", tmpBook.id); // 삭제 진행


	printf("책 정보가 삭제되었습니다.");
	return 0;
}

//책 검색 기능 함수 
int search_book(MYSQL* conn) {
	MYSQL_ROW row;
	MYSQL_RES* result;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	book tmpBook = {0,};
	char query[500] = {0, };

	int i = 0;

	printf("검색 책 이름 입력 > ");
	scanf("%[^\n]s", tmpBook.title); rewind(stdin);

	sprintf(query,
		"SELECT * FROM books_info WHERE title LIKE '%%%s%%'", tmpBook.title);

	query_stat = mysql_query(conn, query) ; //c에서 문자열 출력을 위해서는 %%2번씩 써야했음
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return 100;
	}

	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("출력할 데이터가 없습니다.\n");
		return 0;
	}

	//헤더 
	print_header();

	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	return 0;
}

void print_header(void) { // 모든 출력 결과에 같이 나오도록 함
	printf("[번호]  [책제목]  [저자]  [장르]  [출판일]  [페이지 수]  [출판사]  [가격]\n"); 
	printf("=========================================================================\n");
}
