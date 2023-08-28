SELECT menu.pizza_name,
    pizzeria.name as pizzeria_name,
    menu.price
FROM menu
    INNER JOIN pizzeria on menu.pizzeria_id = pizzeria.id
WHERE menu.pizza_name = 'mushroom pizza'
    OR menu.pizza_name = 'pepperoni pizza'
ORDER BY pizza_name,
    pizzeria_name