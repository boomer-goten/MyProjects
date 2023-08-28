CREATE VIEW v_price_with_discount AS
SELECT person.name as name,
    menu.pizza_name,
    menu.price,
    (0.9 * menu.price)::bigint as discount_price
FROM person
    INNER JOIN person_order on person.id = person_order.person_id
    INNER JOIN menu on menu.id = person_order.menu_id
ORDER BY person.name,
    menu.pizza_name;
SELECT *
FROM v_price_with_discount