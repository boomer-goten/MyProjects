SELECT person.address,
    pizzeria.name,
    count(person.address) as count_of_orders
FROM person
    INNER JOIN person_order on person.id = person_order.person_id
    INNER JOIN menu on person_order.menu_id = menu.id
    INNER JOIN pizzeria on pizzeria.id = menu.pizzeria_id
GROUP BY person.address,
    pizzeria.name
ORDER BY address,
    name