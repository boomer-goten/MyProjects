SELECT action_date,
    (
        SELECT format(
                '%s (age:%s)',
                name,
                age
            ) as person_name
        FROM person
        WHERE person.id = person_id
    )
FROM (
        SELECT order_date as action_date,
            person_id as person_id
        FROM person_order
    ) s
ORDER BY action_date,
    person_name