SELECT person.name,
    menu.pizza_name,
    menu.price,
    (
        menu.price - menu.price * (person_discounts.discount / 100)
    )::REAL as discount_price,
    pizzeria.name as pizzeria_name
FROM person_order
    INNER JOIN person on person.id = person_order.person_id
    INNER JOIN menu on menu.id = person_order.menu_id
    INNER JOIN pizzeria on pizzeria.id = menu.pizzeria_id
    INNER JOIN person_discounts on menu.pizzeria_id = person_discounts.pizzeria_id
    and person.id = person_discounts.person_id
ORDER BY name,
    pizza_name