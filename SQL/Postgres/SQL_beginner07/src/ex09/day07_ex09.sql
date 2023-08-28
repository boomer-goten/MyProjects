SELECT person.address,
    (
        max(person.age) - (min(person.age)::float / max(person.age))
    )::numeric(10, 2) as formula,
    (sum(person.age)::float / count(address))::numeric(10, 2) as average,
    (
        CASE
            WHEN (
                max(person.age)::float - (min(person.age) / max(person.age))
            ) >= (sum(person.age)::float / count(person.age)) then true
            else false
        END
    ) as comparsion
FROM person
GROUP BY person.address
ORDER BY address