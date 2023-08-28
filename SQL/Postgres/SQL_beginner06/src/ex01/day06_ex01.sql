INSERT INTO person_discounts
SELECT ROW_NUMBER() OVER () as id,
    person_id,
    pizzeria_id,
    (
        CASE
            WHEN count(person_id) = 1 then 10.5
            WHEN count(person_id) = 2 then 22
            else 30
        END
    ) as discount
FROM person_order
    INNER JOIN menu on menu_id = menu.id
GROUP BY person_id,
    pizzeria_id
ORDER BY person_id,
    pizzeria_id;
SELECT *
FROM person_discounts