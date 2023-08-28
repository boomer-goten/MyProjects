with DEN as (
    SELECT person.id as person_id,
        pizzeria.id as pizzeria_id
    FROM person,
        pizzeria
    WHERE person.name = 'Denis'
        and pizzeria.name = 'Dominos'
),
IRI as (
    SELECT person.id as person_id,
        pizzeria.id as pizzeria_id
    FROM person,
        pizzeria
    WHERE person.name = 'Irina'
        and pizzeria.name = 'Dominos'
)
insert into person_visits
SELECT MAX(person_visits.id) + 2 as max_id,
    DEN.person_id,
    DEN.pizzeria_id as pizzeria_id,
    '2022-02-24'::date
FROM person_visits,
    DEN
GROUP BY 2,
    3
UNION
SELECT MAX(person_visits.id) + 1 as max_id,
    IRI.person_id,
    IRI.pizzeria_id as pizzeria_id,
    '2022-02-24'::date
FROM person_visits,
    IRI
GROUP BY 2,
    3
RETURNING *;