with result as (
    SELECT person.name as person_name1,
        pers.name as person_name2,
        person.address
    FROM person
        FULL JOIN (
            SELECT *
            FROM person
        ) as pers on person.id > pers.id
    WHERE person.address = pers.address
)
SELECT *
FROM result
ORDER BY person_name1,
    person_name2,
    address