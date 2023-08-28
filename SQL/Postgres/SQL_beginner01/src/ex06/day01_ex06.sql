SELECT action_date,
    (
        SELECT name as person_name
        FROM person
        WHERE person.id = person_id
    )
FROM (
        (
            SELECT order_date as action_date,
                person_id as person_id
            FROM person_order
        )
        INTERSECT
        (
            SELECT visit_date,
                person_id
            FROM person_visits
        )
    ) s
ORDER BY action_date,
    person_name DESC