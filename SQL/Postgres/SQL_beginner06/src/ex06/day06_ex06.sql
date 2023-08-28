DROP SEQUENCE IF EXISTS seq_person_discounts;
CREATE SEQUENCE seq_person_discounts AS bigint INCREMENT 1 START 1;
SELECT setval(
        'seq_person_discounts',
        (
            SELECT max(id)
            FROM person_discounts
        )
    );
ALTER TABLE person_discounts
alter column id
SET default nextval('seq_person_discounts');
-- INSERT INTO person_discounts(person_id, pizzeria_id)
-- values (1, 2);