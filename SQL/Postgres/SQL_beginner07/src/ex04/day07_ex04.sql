with visits as (
    SELECT person.name,
        person_visits.pizzeria_id
    FROM person_visits
        INNER JOIN person on person.id = person_visits.person_id
    GROUP BY person.name,
        person_visits.pizzeria_id
)
SELECT visits.name,
    count(visits.name) as count_of_visits
FROM visits
GROUP BY visits.name
HAVING count(visits.name) > 3