SELECT a.name , b.bonus
FROM Employee as a
LEFT JOIN Bonus as b
ON a.empID = b.empID
WHERE b.bonus < 1000 OR b.bonus IS NULL;