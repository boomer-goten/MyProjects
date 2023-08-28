with kate_visit as (
    SELECT id as menu_id
    FROM menu
    WHERE id not in (
            SELECT menu_id
            FROM person_order
        )
)
SELECT *
FROM kate_visit
ORDER BY menu_id