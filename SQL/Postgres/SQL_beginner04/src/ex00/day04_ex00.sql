CREATE VIEW v_persons_male AS
SELECT *
FROM person
WHERE gender = 'male';
CREATE VIEW v_persons_female AS
SELECT *
FROM person
WHERE gender = 'female';
SELECT *
FROM v_persons_male;
SELECT *
FROM v_persons_female