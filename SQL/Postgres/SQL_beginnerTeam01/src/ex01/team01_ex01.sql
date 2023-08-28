INSERT INTO currency
VALUES (100, 'EUR', 0.85, '2022-01-01 13:29');
INSERT INTO currency
VALUES (100, 'EUR', 0.79, '2022-01-08 13:29');

WITH numbered_balance AS
    (SELECT ROW_NUMBER() OVER(
        ORDER BY user_id
        ) AS balance_operation_id,
         user_id,
         money,
         currency_id,
         updated
     FROM balance
), tmp AS
    (SELECT balance_operation_id,
            u.name,
            u.lastname,
            money,
            rate_to_usd,
            c.name AS currency_name,
            b.updated AS balance_updated,
            c.updated AS currecy_updated,
            b.updated - c.updated AS d
     FROM numbered_balance b
         LEFT JOIN "user" u ON user_id = u.id
         JOIN currency c ON currency_id = c.id
), tmp_minutes AS
    (SELECT balance_operation_id,
            name,
            lastname,
            money,
            rate_to_usd,
            currency_name,
            1 / (
                date_part('day', d) * 24 * 60 + date_part('hour', d) * 60 + date_part('minute', d)
                )::REAL AS delta_time
     FROM tmp
     ORDER BY 1 DESC, 2 ASC
)

SELECT COALESCE(name, 'not defined') AS name,
       COALESCE(lastname, 'not defined') AS lastname,
       currency_name,
       money * rate_to_usd AS currency_in_usd
FROM tmp_minutes AS t1
WHERE delta_time = (SELECT (CASE
                                WHEN max(delta_time) > 0 THEN max(delta_time)
                                ELSE min(delta_time)
                            END)
                    FROM tmp_minutes AS t2
                    WHERE t1.balance_operation_id = t2.balance_operation_id)
ORDER BY 1 DESC, 2 ASC, 3 ASC;
