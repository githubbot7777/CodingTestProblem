--문제:https://school.programmers.co.kr/learn/courses/30/lessons/131123
/*
IN으로 여러칼럼 비교
SELECT *
FROM 테이블명
WHERE (컬럼1, 컬럼2) IN (SELECT 서브쿼리_컬럼1, 서브쿼리_컬럼2 FROM 서브쿼리_테이블);
*/
SELECT FOOD_TYPE,REST_ID,REST_NAME,FAVORITES
FROM REST_INFO
WHERE (FOOD_TYPE,FAVORITES) IN (SELECT FOOD_TYPE,MAX(FAVORITES)
                                FROM REST_INFO
                                GROUP BY FOOD_TYPE)
ORDER BY FOOD_TYPE DESC;
