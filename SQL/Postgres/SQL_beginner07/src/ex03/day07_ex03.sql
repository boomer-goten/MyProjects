with visit as (
    SELECT pizzeria.name,
        count(person_visits.pizzeria_id) as count,
        'visit' as action_type
    FROM person_visits
        RIGHT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC,
        pizzeria.name
),
orders as (
    SELECT pizzeria.name,
        count(menu_order.pizzeria_id) as count,
        'order' as action_type
    FROM pizzeria
        LEFT JOIN (
            SELECT *
            FROM person_order
                INNER JOIN menu on menu.id = person_order.menu_id
        ) as menu_order on pizzeria.id = menu_order.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC,
        pizzeria.name
)
SELECT visit.name,
    orders.count + visit.count as total_count
FROM visit,
    orders
WHERE visit.name = orders.name
ORDER BY total_count desc,
    name