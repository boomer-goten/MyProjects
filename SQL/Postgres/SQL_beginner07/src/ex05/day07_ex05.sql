SELECT DISTINCT person.name
FROM person
    INNER JOIN person_order on person.id = person_order.person_id
ORDER BY name