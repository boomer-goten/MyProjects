with forgotten_pizza as (
    SELECT menu.pizza_name,
        menu.price,
        pizzeria.name as pizzeria_name
    FROM menu
        INNER JOIN pizzeria on pizzeria.id = menu.pizzeria_id
    WHERE menu.id not in (
            SELECT menu_id
            FROM person_order
        )
)
SELECT *
FROM forgotten_pizza
ORDER BY pizza_name,
    price