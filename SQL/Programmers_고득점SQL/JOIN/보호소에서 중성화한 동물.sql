--문제:https://school.programmers.co.kr/learn/courses/30/lessons/59045
/*
보호소에서 중성화 수술을 거친 동물 정보를 알아보려 합니다. 
보호소에 들어올 당시에는 중성화1되지 않았지만, 
보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회하는 아이디 순으로 조회하는 SQL 문을 작성해주세요.
*/
--나의풀이
SELECT I.ANIMAL_ID,I.ANIMAL_TYPE,I.NAME
FROM ANIMAL_INS I, (
                    SELECT*
                    FROM ANIMAL_OUTS
                    WHERE SEX_UPON_OUTCOME LIKE 'Spayed%' OR SEX_UPON_OUTCOME LIKE 'Neutered%') O
WHERE I.ANIMAL_ID=O.ANIMAL_ID
AND I.SEX_UPON_INTAKE LIKE 'Intact%'
ORDER BY I.ANIMAL_ID;

--다른풀이(서브쿼리x NOT LIKE 사용)
SELECT O.ANIMAL_ID, O.ANIMAL_TYPE, O.NAME
FROM ANIMAL_INS AS I
INNER JOIN ANIMAL_OUTS AS O
ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE I.SEX_UPON_INTAKE LIKE '%Intact%' AND O.SEX_UPON_OUTCOME NOT LIKE '%Intact%' 
ORDER BY 1
