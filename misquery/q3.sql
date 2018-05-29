SELECT n,
  CASE
    WHEN n % 15 = 0 THEN 'FizzBuzz'
    WHEN n % 3 = 0 THEN 'Fizz'
    WHEN n % 5 = 0 THEN 'Buzz'
    ELSE CAST(n AS TEXT)
  END AS f
FROM GENERATE_SERIES(
  (SELECT a
  FROM tbl),
  (SELECT b
  FROM tbl)
) AS t(n)
