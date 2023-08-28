with DEN as (
    SELECT person_all_id + max(person_order.id) as id,
        person_all_id as person_id,
        menu.id as menu_id,
        '2022-02-25'::date
    FROM person,
        menu,
        generate_series(
            (
                SELECT min(person.id)
                FROM person
            ),
            (
                SELECT max(person.id)
                FROM person
            ),
            1
        ) as person_all_id,
        person_order
    WHERE menu.pizza_name = 'greek pizza'
    GROUP BY 2,
        3
    ORDER BY id
)
insert into person_order
SELECT *
FROM DEN
RETURNING *;