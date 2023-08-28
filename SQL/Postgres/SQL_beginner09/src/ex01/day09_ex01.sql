CREATE OR REPLACE FUNCTION fnc_trg_person_update_audit() RETURNS TRIGGER AS $fnc_trg_person_update_audit$ BEGIN
INSERT INTO person_audit
SELECT now(),
    'U',
    OLD.*;
RETURN OLD;
END;
$fnc_trg_person_update_audit$ LANGUAGE plpgsql;
CREATE TRIGGER trg_person_update_audit
AFTER
UPDATE ON person FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_update_audit();
UPDATE person
SET name = 'Bulat'
WHERE id = 10;
UPDATE person
SET name = 'Damir'
WHERE id = 10;
SELECT *
FROM person_audit