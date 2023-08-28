DROP FUNCTION fnc_person_visits_and_eats_on_date;
CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(
        pperson varchar default 'Dmitriy',
        pprice numeric default 500,
        pdate date default '2022-01-08'
    ) RETURNS TABLE(pizzeria_name varchar) AS $lag$ BEGIN RETURN query
SELECT DISTINCT pizzeria.name as pizzeria_name
FROM person_visits
    INNER JOIN person on person.id = person_visits.person_id
    INNER JOIN person_order on person.id = person_order.person_id
    INNER JOIN menu on menu.id = person_order.menu_id
    INNER JOIN pizzeria on person_visits.pizzeria_id = pizzeria.id
WHERE person.name = $1
    and person_order.order_date = $3
    and person_visits.visit_date = $3
    and menu.price < $2;
END;
$lag$ LANGUAGE plpgsql;
select *
from fnc_person_visits_and_eats_on_date(pprice := 800);
select *
from fnc_person_visits_and_eats_on_date(
        pperson := 'Anna',
        pprice := 1300,
        pdate := '2022-01-01'
    );