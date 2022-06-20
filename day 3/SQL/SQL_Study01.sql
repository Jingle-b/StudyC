-- SQL (structured Query Language)

-- 1. SELECT QUERY (데이터 조회)
-- 기본 쿼리
SELECT *	-- ALL  
	FROM contact;
    
SELECT id, name, pheonenum, email, addr
	FROM contact;

-- 데이터가 몇 개인지 확인하는 쿼리
SELECT COUNT(*)
	FROM contact;

-- 데이터를 원하는 컬럼만 조회
SELECT name, phonenum, email
	FROM contact;
    
-- 원하는 결과만 조회
SELECT *
	FROM contact
	WHERE id = 3; -- 대소문자 구분 없음 
    -- PK(기본키) 조회가 일반적이다. (이름은 중복 가능)

-- 이름으로 조회하는 쿼리
SELECT *
	FROM contact
    WHERE name = '홍길순'; -- DB에서 같은지 비교 // 이름으로 찾은 경우 모든 경우가 찾아진다. 
    
-- 2. INSERT QUERY
INSERT INTO contact
(name, phonenum, email, addr) VALUES -- id와 같은 AI PK로 표현된 것은 언급하지 않는다.
('홍길순','010-1111-8888','hgs@daum.net','횡성') contact;-- dB에서 문자열은 홑따옴표로 표현한다. 

-- NULL 값 제외 
INSERT INTO contact
(name) VALUES ('손흥민'); -- NOT NULL 선택해서 추가할 수 없다. (데이터 입력 불가)

INSERT INTO contact
(name, phonenum) VALUES ('손흥민', '010-7891-0123');  -- column 값이 NOT NULL인 것은 모두 입력되어야 한다. 

-- 컬럼이 4개인데 4개 다 데이터를 넣겠다고 하는 경우 
INSERT INTO contact 
(name, phonenum, email, addr)
VALUES
('이동욱', '010-6868-5656', 'ldw@gmail.com', '서울');

-- 데이터 수정 
-- 홍길동 id = 1, phonenum = 010-0000-9999 ---> 010-7777-6648
UPDATE contact SET 
		phonenum = '010-7777-6648'
    WHERE id = 1; -- where 사용해야 원하는 값만 수정할 수 있다. 

-- 컬럼이 한 개 이상 변경되는 경우
UPDATE contact SET 
		phonenum = '010-2222-3333', -- 한 줄이 하나의 컬럼이므로 쉼표로 구분 후 엔터해야 한다.(쉼표 필수!!) 
        email = 'gdhong@yahoo.com'
    WHERE id = 1; -- WHERE 필수 
    
-- 4. DELETE 삭제 쿼리 
DELETE FROM contact
	WHERE id = 4; -- WHERE 필수
    