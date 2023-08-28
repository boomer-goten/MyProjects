(SELECT all_tours.total_cost,
        tour
FROM all_tours,
    (
        SELECT min(total_cost) as total_cost
        FROM all_tours
    ) as c
WHERE all_tours.total_cost = c.total_cost)
UNION
(SELECT all_tours.total_cost,
        tour
FROM all_tours,
    (
        SELECT max(total_cost) as total_cost
        FROM all_tours
    ) as c
WHERE all_tours.total_cost = c.total_cost)
ORDER BY total_cost, tour;