-- 1) Инициализируются две транзакции с одного пользователя и с другого
-- 2) Делается select с первой сесиии
-- 3) делается update со второй сессии мы не получим ошибок, так как в первой сессии
-- таблица не меняется поэтому "ОШИБКА: не удалось сериализовать доступ из-за параллельного изменения" такого нет,
-- и выполнение операции будет похоже на пункт 5. Этот уровень отличается от Read Committed тем, что запрос в 
-- транзакции данного уровня видит снимок данных на момент начала первого оператора в транзакции 
-- (не считая команд управления транзакциями), а не начала текущего оператора. Таким образом, 
-- последовательные команды SELECT в одной транзакции видят одни и те же данные; они не видят изменений, 
-- внесённых и зафиксированных другими транзакциями после начала их текущей транзакции.
-- 4) Поэтому изменения внесутся только после коммита первой сессии