with DEN as (
    SELECT person.id as person_id,
        menu.id as menu_id
    FROM person,
        menu
    WHERE person.name = 'Denis'
        and menu.pizza_name = 'sicilian pizza'
),
IRI as (
    SELECT person.id as person_id,
        menu.id as menu_id
    FROM person,
        menu
    WHERE person.name = 'Irina'
        and menu.pizza_name = 'sicilian pizza'
)
insert into person_order
SELECT MAX(person_order.id) + 2 as max_id,
    DEN.person_id,
    DEN.menu_id as menu_id,
    '2022-02-24'::date
FROM person_order,
    DEN
GROUP BY 2,
    3
UNION
SELECT MAX(person_order.id) + 1 as max_id,
    IRI.person_id,
    IRI.menu_id as menu_id,
    '2022-02-24'::date
FROM person_order,
    IRI
GROUP BY 2,
    3
RETURNING *;