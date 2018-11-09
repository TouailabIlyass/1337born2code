ldapsearch -Q "uid=z*" | grep "cn:" | sort --ignore-case -r | cut -c 5-
