## Part 1. Готовый докер
##### Взять официальный докер образ с **nginx** и выкачать его при помощи `docker pull`
- Установим docker на компьютере командой `sudo snap install docker`
    - ![Установка docker](./screenshots/Part_1_1.png "Установка docker")
- Посмотрим все доступные образы nginx командой `sudo docker research nginx`
    - ![Все образы nginx](./screenshots/Part_1_2.png "Все доступные образы nginx")
- Возьмем официальный docker образ nginx и выкачаем его командой `docker pull nginx`
    - ![Официальный образ nginx](./screenshots/Part_1_3.png "Установка образа nginx")
##### Проверить наличие докер образа через `docker images nginx`
- ![Наличие образа nginx](./screenshots/Part_1_4.png "Наличие образа nginx")
##### Запустить докер образ через `sudo docker run -d [image_id|repository]`, командой `docker run -d 2b7d6430f78d nginx`
- ![Запуск образа](./screenshots/Part_1_5.png "Запуск образа nginx")
##### Проверить, что образ запустился через `sudo docker ps`
- ![Проверка запуска образа nginx](./screenshots/Part_1_6.png "Проверка процесса docker nginx")
##### Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]` командой `sudo docker inspect 886adc7f867c`
- ![Вызов команды](./screenshots/Part_1_7.png "Вызов информации об образе")
- Размер контейнера выводиться в байтах на скриншоте указан размер 67108864 что можно перевести в мегабайты и получить 67108864/1024/1024=64 МБ 
    - ![Размер контейнера](./screenshots/Part_1_8.png "Размер контейнера")
- ![Замапленный порт](./screenshots/Part_1_9.png "Замапленные порты")
- ![IP контейнера](./screenshots/Part_1_10.png "IP контейнера")
##### Остановить докер образ через `docker stop [container_id|container_name]` командой `sudo docker stop 886adc7f867c`
- ![Остановка docker образа](./screenshots/Part_1_11.png "Остановка docker образа")
##### Проверить, что образ остановился через `docker ps` командой `sudo docker ps`
- ![Проверка остановки образа nginx](./screenshots/Part_1_12.png "Проверка процесса docker nginx")
##### Запустить докер с замапленными портами 80 и 443 на локальную машину через команду *run* командой `sudo docker run -p 80:80/tcp -p 443:443/tcp -d 2b7d6430f78d`
- ![Запуск образа с открытием 80 и 443 порта](./screenshots/Part_1_13.png "Запуск образа с открытием 80 и 443 порта")
##### Проверить, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**
- ![Стартовая страница nginx](./screenshots/Part_1_14.png "стартовая траница nginx")
##### Перезапустить докер контейнер через `docker restart [container_id|container_name]` комндой `sudo docker restart 41f0e59e10f6` и проверить, что контейнер запустился командой `sudo docker ps`
- ![Перезапуск и проверка работы docker образа](./screenshots/Part_1_15.png "Перезапуск и проверка работы docker образа")

## Part 2. Операции с контейнером
##### Прочитать конфигурационный файл *nginx.conf* внутри докер образа через команду *exec* командой `sudo docker exec dfab919d3a24 cat ./etc/nginx/nginx.conf`
- ![Просмотр файла nginx.conf](./screenshots/Part_2_1.png "Просмотр файла nginx.conf")
##### Создать на локальной машине файл *nginx.conf* и настройка в нем по пути */status* отдачу страницы статуса сервера **nginx**
- ![Настройка nginx.conf](./screenshots/Part_2_2.png "Настройка nginx.conf")
- Cоздать на локальной машине файл default.conf c конфигурацией на скриншоте
- ![Настройка default.conf](./screenshots/Part_2_3.png "Настройка default.conf")
##### Скопировать созданный файл *nginx.conf* внутрь докер образа через команду `docker cp` командой `sudo docker cp it/DO5_SimpleDocker-0/src/nginx.conf dfab919d3a24:/etc/nginx/nginx.conf`
##### Скопировать созданный файл *default.conf* внутрь докер образа через команду `docker cp` командой `sudo docker cp it/DO5_SimpleDocker-0/src/default.conf dfab919d3a24:/etc/nginx/conf.d/default.conf`
- ![Копирование nginx.conf в контейнер](./screenshots/Part_2_4.png "Копирование nginx.conf в контейнер и просмотр его содержимого")
- ![Копирование default.conf в контейнер](./screenshots/Part_2_5.png "Копирование default.conf в контейнер и просмотр его содержимого")
##### Перезапустить **nginx** внутри докер образа через команду *exec* командой `sudo docker exec dfab919d3a24 nginx -s reload`
- ![Перезапуск nginx](./screenshots/Part_2_6.png "Перезапуск nginx")
##### Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
- ![Вывод статуса](./screenshots/Part_2_7.png "Вывод статуса сервера")
##### Экспортировать контейнер в файл *container.tar* через команду *export* командой `sudo docker export dfab919d3a24 > cont.tar`
- ![Создание архива](./screenshots/Part_2_8.png "Cоздание архива")
##### Остановить контейнер командой `sudo docker stop dfab919d3a24`
- ![Остановка контейнера](./screenshots/Part_2_9.png "Остановка контейнера")
##### Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры командой `sudo docker rmi -f 2b7d6430f78d`
- ![Удаление образа](./screenshots/Part_2_10.png "Удаление образа")
##### Удалить остановленный контейнер командой `sudo docker rm dfab919d3a24`
- ![Удаление контейнера](./screenshots/Part_2_11.png "Удаление контейнера")
##### Импортировать контейнер обратно через команду *import* командой `sudo docker import cont.tar ngin`
- ![Импорт архива](./screenshots/Part_2_12.png "Импорт контейнера")
##### Запустить импортированный контейнер командой `sudo docker run -p 80:80/tcp -p 443:443/tcp -dit my_ngin /bin/bash` и запустить сервер командой `sudo docker exec 160032eb14ff service nginx start`
- ![Запуск импортированного архива](./screenshots/Part_2_13.png "Запуск")
- ![Запуск сервера nginx](./screenshots/Part_2_14.png "Запуск сервера nginx")
##### Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
- ![Запуск странички](./screenshots/Part_2_15.png "Запуск странички")
