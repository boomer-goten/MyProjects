DROP FUNCTION func_minimum;
CREATE FUNCTION func_minimum(VARIADIC arr numeric []) RETURNS numeric AS $$
DECLARE s numeric := arr [1];
BEGIN FOR i IN 2..array_length(arr, 1) LOOP IF arr [i] < s THEN s = arr [i];
END IF;
END LOOP;
RETURN s;
END;
$$ LANGUAGE plpgsql;
SELECT func_minimum(VARIADIC arr => ARRAY [10.0, -1.0, 5.0, 4.4]);