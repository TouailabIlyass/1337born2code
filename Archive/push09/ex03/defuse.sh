#!/bin/sh

out="$(stat -f %a bomb.txt)"
echo $(($out - 1))
