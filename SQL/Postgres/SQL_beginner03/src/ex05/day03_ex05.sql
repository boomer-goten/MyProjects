with ordered as (
    SELECT *
    FROM (
            SELECT pizzeria_id
            FROM person_visits
                INNER JOIN person on person.id = person_visits.person_id
            WHERE person.name = 'Andrey'
            EXCEPT
            SELECT DISTINCT menu.pizzeria_id
            FROM person_order
                INNER JOIN person on person.id = person_order.person_id
                INNER JOIN menu on person_order.menu_id = menu.id
            WHERE person.name = 'Andrey'
        ) c
)
SELECT pizzeria.name
FROM ordered
    INNER JOIN pizzeria on pizzeria.id = ordered.pizzeria_id