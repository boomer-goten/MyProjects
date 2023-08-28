with result as (
    SELECT menu.pizza_name,
        pizzeria.name as pizzeria_name1,
        pizzerias.name as pizzeria_name2,
        menu.price
    FROM menu
        FULL JOIN (
            SELECT *
            FROM menu
        ) as menus on menu.id > menus.id
        INNER JOIN pizzeria on menu.pizzeria_id = pizzeria.id
        INNER JOIN (
            SELECT *
            FROM pizzeria
        ) as pizzerias on menus.pizzeria_id = pizzerias.id
    WHERE menu.price = menus.price
        and menu.pizza_name = menus.pizza_name
)
SELECT *
FROM result
ORDER BY pizza_name