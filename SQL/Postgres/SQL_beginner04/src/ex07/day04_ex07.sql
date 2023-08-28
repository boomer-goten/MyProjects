insert into person_visits with maximum as (
        SELECT MAX(person_visits.id) + 1 as id
        FROM person_visits
    )
SELECT maximum.id as id,
    person_id,
    pizzeria.id as pizzeria_id,
    '2022-01-08'
FROM maximum,
    pizzeria,
    person_visits
    LEFT JOIN person on person.id = person_visits.person_id
WHERE pizzeria.name = 'DoDo Pizza'
    and person.name = 'Dmitriy'
GROUP BY 1,
    2,
    3;
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
SELECT *
FROM mv_dmitriy_visits_and_eats