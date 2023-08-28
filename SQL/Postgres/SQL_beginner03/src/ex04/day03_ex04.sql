with male_order as (
    SELECT DISTINCT pizzeria.name as pizzeria_name
    FROM person_order
        INNER JOIN person on person_order.person_id = person.id
        INNER JOIN menu on menu.id = person_order.menu_id
        INNER JOIN pizzeria on menu.pizzeria_id = pizzeria.id
    WHERE person.gender = 'male'
),
female_order as (
    SELECT DISTINCT pizzeria.name as pizzeria_name
    FROM person_order
        INNER JOIN person on person_order.person_id = person.id
        INNER JOIN menu on menu.id = person_order.menu_id
        INNER JOIN pizzeria on menu.pizzeria_id = pizzeria.id
    WHERE person.gender = 'female'
)
SELECT *
FROM male_order NATURAL
    FULL OUTER JOIN female_order
WHERE male_order.pizzeria_name is NULL
    OR female_order.pizzeria_name is NULL