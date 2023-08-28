SELECT object_name
FROM (
        (
            SELECT name as object_name
            FROM person
            ORDER BY name
        )
        UNION ALL
        (
            SELECT pizza_name
            FROM menu
            ORDER BY pizza_name
        )
    ) c