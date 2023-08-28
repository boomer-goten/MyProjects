SELECT DISTINCT visit_date as missing_date
FROM (
        SELECT person_visits.visit_date
        FROM generate_series(
                '2022-01-01'::date,
                '2022-01-10'::date,
                '1D'
            ) as missing_dat
            INNER JOIN person_visits on person_visits.visit_date = missing_dat
        WHERE (
                person_visits.person_id between 1 AND 2
            )
        ORDER BY visit_date
    ) as not_missing_dates NATURAL
    RIGHT JOIN person_visits
WHERE not_missing_dates is NULL
ORDER BY missing_date