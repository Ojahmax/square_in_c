#!/bin/sh
ifconfig -a | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}' | tr -d ' '
