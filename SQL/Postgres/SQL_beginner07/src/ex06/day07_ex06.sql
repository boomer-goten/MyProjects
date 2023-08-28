SELECT pizzeria.name,
    count(pizzeria.id) as count_of_orders,
    (sum(menu.price) / count(menu.id))::numeric(10, 2) as average_price,
    max(menu.price) as max_price,
    min(menu.price) as min_price
FROM person_order
    INNER JOIN menu on person_order.menu_id = menu.id
    INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
GROUP BY pizzeria.name
ORDER BY name