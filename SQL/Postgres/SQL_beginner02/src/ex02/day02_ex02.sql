with visites_dates as (
    SELECT person.id,
        person_visits.visit_date,
        person_visits.pizzeria_id
    FROM person
        FULL JOIN person_visits on (
            person_visits.person_id = person.id
        )
    WHERE (
            person_visits.visit_date between '2022-01-01' AND '2022-01-03'
        )
),
all_visites as (
    SELECT person.name,
        visites_dates.visit_date,
        pizzeria.name as pizzeria_name
    FROM visites_dates
        FULL JOIN person on visites_dates.id = person.id
        FULL JOIN pizzeria on visites_dates.pizzeria_id = pizzeria.id
)
SELECT COALESCE(all_visites.name, '-') as name,
    all_visites.visit_date,
    COALESCE(all_visites.pizzeria_name, '-') as pizzeria_name
FROM all_visites
ORDER BY name,
    visit_date,
    pizzeria_name