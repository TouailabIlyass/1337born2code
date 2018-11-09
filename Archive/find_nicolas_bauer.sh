#!/bin/sh

grep -i ^Nicolas test.txt | grep -i Bauer | grep '[0-9]\{3\}-[0-9]\{4\}' | grep -Eo "(\([0-9]\))?[0-9-]{1,}"