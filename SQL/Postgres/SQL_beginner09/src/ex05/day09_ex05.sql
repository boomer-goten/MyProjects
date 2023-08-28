DROP FUNCTION fnc_persons_female;
DROP FUNCTION fnc_persons_male;
-- DROP FUNCTION fnc_persons
CREATE OR REPLACE FUNCTION fnc_persons(pgender varchar default 'female') RETURNS setof person AS $lag$
SELECT *
FROM person
WHERE person.gender = $1;
$lag$ LANGUAGE sql;
SELECT *
FROM fnc_persons(pgender := 'male');
SELECT *
FROM fnc_persons();