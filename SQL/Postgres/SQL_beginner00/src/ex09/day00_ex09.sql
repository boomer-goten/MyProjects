SELECT DISTINCT (
        SELECT name
        FROM person
        WHERE id = person_id
    ) as person_name,
    (
        SELECT name
        FROM pizzeria
        WHERE id = pizzeria_id
    ) as pizzeria_name
FROM (
        SELECT *
        FROM person_visits
        WHERE visit_date BETWEEN '2022-01-07' AND '2022-01-09'
    ) as pv
ORDER BY person_name