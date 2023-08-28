with personal as (
    SELECT *
    FROM person_order
        INNER JOIN person on person_order.person_id = person.id
    WHERE person.gender = 'male'
        AND (
            person.address = 'Moscow'
            OR person.address = 'Samara'
        )
)
SELECT DISTINCT name
FROM personal
    INNER JOIN menu on personal.menu_id = menu.id
WHERE menu.pizza_name in ('mushroom pizza', 'pepperoni pizza')
ORDER BY name DESC