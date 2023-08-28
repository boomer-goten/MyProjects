#!/bin/bash
/usr/sbin/setsebool httpdcannetwork_connect true
service nginx start


