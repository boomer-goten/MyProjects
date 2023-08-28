DELETE FROM person_order
where order_date = '2022-02-25'::date;
DELETE FROM menu
where pizza_name = 'greek pizza';