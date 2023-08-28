SELECT person.name,
    count(person_visits.person_id) as count_of_visits
FROM person_visits
    INNER JOIN person ON person.id = person_visits.person_id
GROUP BY person.name
ORDER BY count_of_visits DESC,
    person.name
LIMIT 4