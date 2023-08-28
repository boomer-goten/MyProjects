SELECT name,
    rating
FROM person_visits
    RIGHT OUTER JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
WHERE person_visits.pizzeria_id is NULL