#!/bin/sh

cat "$@" | grep -i "nicolas\tbauer" | grep -o '\([0-9]\{3\}\-[0-9]\{3\}\-[0-9]\{2\}\)\|\(([0-9]\{3\})[0-9]\{3\}\-[0-9]\{4\}\)\|\([0-9]\{10\}\)\|\([0-9]\{3\}\s[0-9]\{3\}\s[0-9]\{4\}\)' 
