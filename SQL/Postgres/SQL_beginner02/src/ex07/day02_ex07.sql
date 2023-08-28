with personal as (
    SELECT *
    FROM person_visits
        INNER JOIN person on person_visits.person_id = person.id
    WHERE person.name = 'Dmitriy'
        AND person_visits.visit_date = '2022-01-08'
)
SELECT pizzeria.name as pizzeria_name
FROM pizzeria
    INNER JOIN personal on personal.pizzeria_id = pizzeria.id
    INNER JOIN menu on menu.pizzeria_id = pizzeria.id
WHERE menu.price < 800