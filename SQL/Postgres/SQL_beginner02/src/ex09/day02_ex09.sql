WITH females as (
    SELECT *
    FROM person_order
        INNER JOIN person on person_order.person_id = person.id
    WHERE person.gender = 'female'
),
cheese as (
    SELECT *
    FROM females
        INNER JOIN menu on females.menu_id = menu.id
        AND menu.pizza_name = 'cheese pizza'
),
pepperoni as (
    SELECT *
    FROM females
        INNER JOIN menu on females.menu_id = menu.id
        AND menu.pizza_name = 'pepperoni pizza'
)
SELECT cheese.name
FROM cheese
    INNER JOIN pepperoni on cheese.name = pepperoni.name
ORDER BY cheese.name