WITH current_balance AS
    (SELECT DISTINCT user_id,
                     sum(money) AS money,
                     currency_id,
                     type

     FROM balance
     GROUP BY 1, 3, 4
), current_currency AS
    (SELECT *
     FROM currency AS c1
     WHERE updated = (SELECT MAX(updated)
                      FROM currency AS c2
                      WHERE c1.id = c2.id)
), tmp as
    (SELECT DISTINCT u.name,
                     lastname,
                     type,
                     money AS volume,
                     c.name AS currency_name,
                     rate_to_usd AS last_rate_to_usd,
                     (money * rate_to_usd)::REAL total_volume_in_usd
     FROM current_balance
         LEFT JOIN "user" u ON u.id = user_id
         LEFT JOIN current_currency c ON currency_id = c.id
)

SELECT COALESCE(tmp.name, 'not defined') AS name,
       COALESCE(tmp.lastname, 'not defined') AS lastname,
       type,
       volume,
       COALESCE(tmp.currency_name, 'not defined') AS currency_name,
       COALESCE(tmp.last_rate_to_usd, '1') AS last_rate_to_usd,
       COALESCE(tmp.total_volume_in_usd, volume) AS total_volume_in_usd
FROM tmp
ORDER BY 1 DESC, 2 ASC, 3 ASC;
