SELECT DISTINCT v_generated_dates.generate as missing_date
FROM person_visits
    RIGHT JOIN v_generated_dates on person_visits.visit_date = v_generated_dates.generate
where person_visits.visit_date is NULL
ORDER BY missing_date