set enable_seqscan = off;
explain analyze
SELECT menu.pizza_name,
    pizzeria.name as pizzeria_name
FROM menu
    INNER join pizzeria on pizzeria.id = menu.pizzeria_id -- in (pizzeria.id)