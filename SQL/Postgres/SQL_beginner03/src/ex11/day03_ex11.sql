UPDATE menu
SET price = (price * 0.9)::bigint
WHERE pizza_name = 'greek pizza'
RETURNING *;