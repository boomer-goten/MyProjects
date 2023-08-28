with kate_visit as (
    SELECT menu.pizza_name,
        menu.price,
        pizzeria.name as pizzeria_name,
        person_visits.visit_date
    FROM person_visits
        INNER JOIN person on person.id = person_id
        INNER JOIN pizzeria on pizzeria.id = pizzeria_id
        INNER JOIN menu on menu.pizzeria_id = pizzeria.id
    WHERE person.name = 'Kate'
        and price between 800 and 1000
)
SELECT *
FROM kate_visit
ORDER BY pizza_name,
    price,
    pizzeria_name