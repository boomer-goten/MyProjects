CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit() RETURNS TRIGGER AS $fnc_trg_person_delete_audit$ BEGIN
INSERT INTO person_audit
SELECT now(),
    'D',
    OLD.*;
RETURN OLD;
END;
$fnc_trg_person_delete_audit$ LANGUAGE plpgsql;
CREATE TRIGGER trg_person_delete_audit
AFTER DELETE ON person FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_delete_audit();
DELETE FROM person
WHERE id = 10;
SELECT *
FROM person_audit