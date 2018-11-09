#!/bin/bash
find . -name "*.sh" -print | rev | cut -d "/" -f 1 | rev | cut -d "." -f 1
