--문제:https://school.programmers.co.kr/learn/courses/30/lessons/144856

SELECT AUTHOR_ID,AUTHOR_NAME,CATEGORY,SUM(PRICE*SALES) AS TOTAL_SALES
FROM BOOK
INNER JOIN AUTHOR
USING(AUTHOR_ID)
INNER JOIN BOOK_SALES
USING(BOOK_ID)
WHERE SALES_DATE LIKE '2022-01%'
GROUP BY AUTHOR_ID,CATEGORY
ORDER BY AUTHOR_ID,CATEGORY DESC
