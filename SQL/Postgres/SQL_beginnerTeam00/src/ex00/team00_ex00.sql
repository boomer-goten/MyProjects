CREATE TABLE IF NOT EXISTS route (
    point1 varchar(1),
    point2 varchar(1),
    cost integer
);

INSERT INTO route
VALUES ('a', 'b', 10);
INSERT INTO route
VALUES ('a', 'c', 15);
INSERT INTO route
VALUES ('a', 'd', 20);
INSERT INTO route
VALUES ('b', 'a', 10);
INSERT INTO route
VALUES ('b', 'c', 35);
INSERT INTO route
VALUES ('b', 'd', 25);
INSERT INTO route
VALUES ('c', 'a', 15);
INSERT INTO route
VALUES ('c', 'b', 35);
INSERT INTO route
VALUES ('c', 'd', 30);
INSERT INTO route
VALUES ('d', 'a', 20);
INSERT INTO route
VALUES ('d', 'b', 25);
INSERT INTO route
VALUES ('d', 'c', 30);


CREATE OR REPLACE FUNCTION ret_doroga(pint_1 char, pint_2 char) RETURNS integer AS $$
SELECT cost
FROM route
WHERE route.point1 = pint_1
    and route.point2 = pint_2;
$$ LANGUAGE SQL;
CREATE OR REPLACE FUNCTION my_sum(string char []) RETURNS integer AS $$
DECLARE s int8 := 0;
BEGIN FOR i IN 2..array_length(string, 1) LOOP s := s + ret_doroga(string [i-1], string [i]);
END LOOP;
RETURN s;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE VIEW all_tours AS WITH RECURSIVE t(destination, tour, iteration) AS (
        SELECT point1,
            ARRAY [point1]::char(1) [],
            0
        FROM route
        WHERE point1 = 'a'
        UNION
        SELECT DISTINCT point1 AS destination,
            (
                CASE
                    WHEN array_position (tour, point1) is NULL THEN (t.tour || point1)::char(1) []
                    ELSE t.tour
                END
            ) as tour,
            t.iteration + 1
        FROM route,
            t
        WHERE t.iteration < 4
            and point1 != 'a'
    ),
    tours as (
        SELECT DISTINCT tour
        FROM t
        WHERE t.iteration = 4
            and array_length (tour, 1) = 4
    ),
    result_tour as (
        SELECT array_append (tour, 'a') as tour
        FROM tours
    )
SELECT my_sum(tour) as total_cost,
       tour as tour
FROM result_tour
ORDER BY total_cost, tour;

SELECT all_tours.total_cost,
       tour
FROM all_tours,
    (
        SELECT min(total_cost) as total_cost
        FROM all_tours
    ) as c
WHERE all_tours.total_cost = c.total_cost
ORDER BY total_cost, tour;