insert into menu
SELECT MAX(menu.id) + 1 as max_id,
    menu.pizzeria_id as pizzeria_id,
    'sicilian pizza',
    900
FROM menu
    INNER JOIN pizzeria on pizzeria.id = menu.pizzeria_id
WHERE pizzeria.name = 'Dominos'
GROUP BY 2
RETURNING *;