#!/bin/bash
ldapsearch -Q "sn=*bon*" | sed '/filter/ d' | grep sn | wc -l | sed 's/ //g'
