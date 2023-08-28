SELECT order_date,
    (
        SELECT format(
                '%s (age:%s)',
                name,
                age
            ) as person_name
        FROM person
        WHERE person.id = person_id
    )
FROM person_order NATURAL
    LEFT JOIN person
ORDER BY order_date,
    person_name