SELECT (
        SELECT name
        FROM person
        WHERE id = person_id
    ) as NAME,
    (
        SELECT name = 'Denis'
        FROM person
        WHERE id = person_id
    ) as check_name
FROM person_order
WHERE person_order.order_date = '2022-01-07'
    AND (
        person_order.menu_id = 13
        OR person_order.menu_id = 14
        OR person_order.menu_id = 18
    )