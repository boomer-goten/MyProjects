#!/bin/bash
sudo docker build -t serv:my .
sudo docker run -p 80:81/tcp -p 443:443/tcp -it serv:my