with male_visits as (
    SELECT DISTINCT pizzeria.name as pizzeria_name
    FROM person_visits
        INNER JOIN person on person_visits.person_id = person.id
        INNER JOIN pizzeria on person_visits.pizzeria_id = pizzeria.id
    WHERE person.gender = 'male'
),
female_visits as (
    SELECT DISTINCT pizzeria.name as pizzeria_name
    FROM person_visits
        INNER JOIN person on person_visits.person_id = person.id
        INNER JOIN pizzeria on person_visits.pizzeria_id = pizzeria.id
    WHERE person.gender = 'female'
)
SELECT *
FROM male_visits NATURAL
    FULL OUTER JOIN female_visits
WHERE male_visits.pizzeria_name is NULL
    OR female_visits.pizzeria_name is NULL