SELECT DISTINCT l1.num AS ConsecutiveNums
FROM (
    SELECT num,
           LEAD(num, 1) OVER (ORDER BY id) AS next_num1,
           LEAD(num, 2) OVER (ORDER BY id) AS next_num2
    FROM Logs
) l1
WHERE l1.num = l1.next_num1 AND l1.num = l1.next_num2;