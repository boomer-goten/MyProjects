create index idx_person_name on person(upper(name));
set enable_seqscan = off;
explain analyze
SELECT name
FROM person
WHERE upper(name) = 'DENIS'