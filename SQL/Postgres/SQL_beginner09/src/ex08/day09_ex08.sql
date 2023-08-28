-- DROP FUNCTION fnc_fibonacci;
CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop integer default 10) RETURNS TABLE(number integer) AS $lag$ BEGIN RETURN query with recursive fibonacci(a, b) as (
        select 0::int,
            1::int
        union all
        select b,
            a + b
        from fibonacci
        where b < pstop
    )
SELECT a
from fibonacci;
END;
$lag$ LANGUAGE plpgsql;
select *
from fnc_fibonacci();
select *
from fnc_fibonacci(100);