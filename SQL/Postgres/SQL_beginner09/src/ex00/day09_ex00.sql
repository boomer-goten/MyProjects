CREATE TABLE person_audit (
    created TIMESTAMP with time zone default CURRENT_TIMESTAMP not null,
    type_event char(1) default 'I' not null,
    row_id bigint not null,
    name varchar not null,
    age integer not null default 10,
    gender varchar default 'female' not null,
    address varchar
);
alter table person_audit
add constraint ch_type_event check (type_event in ('I', 'D', 'U')),
    add constraint ch_gender check (gender in ('female', 'male'));
CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit() RETURNS TRIGGER AS $fnc_trg_person_insert_audit$ BEGIN
INSERT INTO person_audit
SELECT now(),
    'I',
    NEW.*;
RETURN NEW;
END;
$fnc_trg_person_insert_audit$ LANGUAGE plpgsql;
CREATE TRIGGER trg_person_insert_audit
AFTER
INSERT ON person FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_insert_audit();
INSERT INTO person(id, name, age, gender, address)
VALUES (10, 'Damir', 22, 'male', 'Irkutsk');
SELECT *
FROM person_audit