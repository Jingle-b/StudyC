-- Sample DB Employees 학습
-- Department 부서 테이블 조회
SELECT dp.dept_no, dp.dept_name -- 처음 볼 때 정도에만 *로 select 한다. (그런데 점점 안써야함! 조건을 달아서 확인할 수 있어야 한다)
	FROM departments as dp;
SELECT  dm.emp_no, dm.dept_no, dm.from_date, dm.to_date 
	FROM dept_manager as dm;	 
    
-- 한 번에 볼 수 있도록 합치기 위해 먼저 as 별명 식으로 설정한다. 


-- 합치기 (조인) INNER JOIN 	-- 가장 많이 쓰는 조인(INNER JOIN으로 표현하는 것이 표준)
SELECT dp.dept_no
	, dp.dept_name -- dp에 있는 데이터  
    /*, dm.emp_no*/  -- 주석처리 하면 삭제처리처럼 된다.   
    , dm.from_date
    , dm.to_date -- dm에 있는 데이터
    , em.emp_no
    , DATE_FORMAT(em.birth_date, '%Y년 %m월 %d일') as '생일' -- 날짜 표기 형식 변경 함수(DATE_FORMAT)
    , CONCAT(em.first_name, ' ', em.last_name) as 'Full Name' -- 테이블에 표기되는 제목도 변경 -- 내용을 순수하게 합침 
    , CASE WHEN em.gender = 'F' THEN '여성'  -- switch case와 같은 구조 가능
		   WHEN  em.gender = 'M' THEN '남성' 
           ELSE '오류' END as '성별'
           -- em에 있는 데이터
		-- 겹치는 dp.dept_no를 지워둔 상태
        -- 쭉 연결해서 작성한다면 직접 선택해서 지워야 하는데, 이는 실무에서 쓸만한 방식은 아니다.
		-- 그래서 세로로 나타낸다. 
	FROM departments as dp -- 기준 테이블 
    INNER JOIN dept_manager as dm -- 합칠 테이블 
    ON dp.dept_no = dm.dept_no -- 같은 것을 합치는 코드
    -- 데이터를 살펴보면 dept_no가 겹침을 확인할 수 있음(조건으로 설정 가능); 
    -- dp와 dm에서의 dept_no가 모두 같다. 
    INNER JOIN employees as em -- 기준 : dept_manager as dm  - emp.no가 dept_manager에 있으므로
    ON em.emp_no = dm.emp_no;
    
/*
-- 이렇게 함쳤을 때, emp_no를 통해서는 직원의 이름을 알 수 없다 -> 또다른 기준 테이블인 employees 가 필요한 이유
SELECT em.emp_no, em.birth_date, em.first_name, em.last_name, em.gender, em.hire_date -- *로 어떤 항목이 있는지 확인해서 결과 보고 작성한다. 
	FROM employees as em; -- 별명
*/ 
    
-- 목표 = em_num이 같은 직원의 이름과 성별을 앞서 만든 테이블에 표현 -> 먼저 항목들부터 위 테이블에 추가한다. 

-- Employees & Salaries
SELECT em.emp_no
	, em.birth_date
	, em.first_name
	, em.last_name
    , em.gender
    , em.hire_date 
	, sl.salary
    , sl.from_date
    , sl.to_date 
FROM employees as em
INNER JOIN salaries as sl
ON em.emp_no = sl.emp_no
WHERE em.emp_no = 10002;  -- join한 결과를 조건을 주어 검색할 수 있음. 

SELECT sl.emp_no
	, sl.salary
    , sl.from_date
    , sl.to_date 
    FROM salaries as sl;
    
-- 통계치 분석 자료
SELECT COUNT(*) FROM salraies; -- 2844047 건
SELECT SUM(salary) FROM salaries;  -- 181,480,757,419 달러

-- 현: 300024건 존재
-- 회사 직원 중 10299번까지의 직원의 
-- 평균 연봉, 연봉 총합, 근무 년수를 출력 
SELECT res.emp_no
	, res.a as '연봉총합' -- a 대신 처음부터 연봉총합이라고 띄어쓰기 없이 붙인 상태로 이름 만들면 가능
	, res.b as '평균연봉' 
    , res.c as '근무년수'
    , emp.first_name
    , emp.last_name
    , emp.gender
FROM (
SELECT sl.emp_no
	, SUM(sl.salary)  as 'a' -- 직원별 총 급여 
    , AVG(sl.salary) as 'b' --  직원별 급여 평균
    , COUNT(sl.salary) as 'c'-- 일한 기간 (year)
	FROM salaries as sl
    WHERE sl.emp_no <= 10299 -- 건수를 줄여서 볼 수 있음 
		-- and COUNT(sl.salary) >= 15 -- where 절은 일반적인 컬럼에만 사용할 수 있다. (통계치로 구성된 컬럼은 사용할 수 없음)
	GROUP BY sl.emp_no -- emp_no를 기준으로 
    HAVING COUNT(sl.salary) >= 15 -- having을 통하면 가능, group by를 사용하는 경우, having 절이 필요한 경우가 생긴다. 
    ) as res 
    -- 이 과정에서, 특정 emp_no인 직원을 알고자 할 때 - 다시 join 사용
    -- 이렇게 만든 테이블은 하나의 가상 테이블이라 할 수 있다. -> 가상 테이블을 크게 묶음 (select * from (가상테이블) as res) 
    
    INNER JOIN employees as emp
    ON res.emp_no = emp.emp_no;



