(
    SELECT pizzeria.name,
        count(person_visits.pizzeria_id) as count,
        'visit' as action_type
    FROM person_visits
        INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC,
        pizzeria.name
    LIMIT 3
)
UNION
(
    SELECT pizzeria.name,
        count(pizzeria.id) as count,
        'order' as action_type
    FROM person_order
        INNER JOIN menu on person_order.menu_id = menu.id
        INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC,
        pizzeria.name
    LIMIT 3
)
ORDER by action_type,
    count DESC