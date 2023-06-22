--문제:https://school.programmers.co.kr/learn/courses/30/lessons/131123
--틀린 제출
SELECT FOOD_TYPE, REST_ID, REST_NAME, MAX(FAVORITES)
FROM REST_INFO
GROUP BY FOOD_TYPE
ORDER BY FOOD_TYPE DESC;

/* 틀린 이유
1. food_type으로 group by를 했으니, food_type과 MAX(Favorites)에 대한 값은 정확하게 나옵니다. 하지만 REST_ID와 REST_NAME의 경우엔 해당 그룹의 첫 번째 행에 있는 값이 나올 거에요
2. 해당 쿼리는 mysql에서는 작동할 수 있지만 엄격한 group by에서는 작동하지 않아요. 
   왜냐하면 group by는 원래 aggregate function이랑 함께 쓰여야 하고 지금 본인이 쓴 쿼리에서는 food_type, rest_id, rest_name이 어떤 row를 가져올지 모르는 상황입니다.
*/

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
