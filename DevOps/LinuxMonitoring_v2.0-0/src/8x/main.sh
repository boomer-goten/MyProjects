#!/bin/bash

stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s

# Для теста на основной машине запустить команду iperf3 -s -f K
# На другой iperf3 -c 192.168.1.51 -f K