-- DROP FUNCTION fnc_persons_female;
-- DROP FUNCTION fnc_persons_male;
CREATE OR REPLACE FUNCTION fnc_persons_female() RETURNS setof person AS $lag$
SELECT *
FROM person
WHERE person.gender = 'female';
$lag$ LANGUAGE sql;
CREATE OR REPLACE FUNCTION fnc_persons_male() RETURNS setof person AS $lag$
SELECT *
FROM person
WHERE person.gender = 'male';
$lag$ LANGUAGE sql;
SELECT *
FROM fnc_persons_female();
SELECT *
FROM fnc_persons_male();