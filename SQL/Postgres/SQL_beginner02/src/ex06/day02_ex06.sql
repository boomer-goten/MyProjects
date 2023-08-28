with personal as (
    SELECT *
    FROM person_order
        INNER JOIN person on person_order.person_id = person.id
    WHERE person.name = 'Denis'
        OR person.name = 'Anna'
)
SELECT menu.pizza_name,
    pizzeria.name as pizzeria_name
FROM menu
    INNER JOIN pizzeria on menu.pizzeria_id = pizzeria.id
    INNER JOIN personal on personal.menu_id = menu.id
ORDER BY pizza_name,
    pizzeria_name