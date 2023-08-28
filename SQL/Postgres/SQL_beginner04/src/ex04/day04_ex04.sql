CREATE VIEW v_symmetric_union AS WITH person_visits_r as (
    SELECT *
    FROM person_visits
    WHERE visit_date = '2022-01-02'
),
person_visits_s as (
    SELECT *
    FROM person_visits
    WHERE visit_date = '2022-01-06'
)
SELECT *
FROM (
        (
            SELECT person_id
            FROM person_visits_r
            EXCEPT
            SELECT person_id
            FROM person_visits_s
        )
        UNION
        (
            SELECT person_id
            FROM person_visits_s
            EXCEPT
            SELECT person_id
            FROM person_visits_r
        )
    ) c;
SELECT *
FROM v_symmetric_union