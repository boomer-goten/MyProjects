#!/bin/bash
gcc -Wall -Werror -Wextra -std=c11 hello_world.c -o hello_world -lfcgi
spawn-fcgi -p 8080 -f ./hello_world
service nginx start
