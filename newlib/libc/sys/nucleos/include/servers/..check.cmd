cmd_/home/devel/tmp/git/nucleos/usr/include/servers/.check := for f in  ; do echo "/home/devel/tmp/git/nucleos/usr/include/servers/$${f}"; done | xargs perl scripts/headers_check.pl /home/devel/tmp/git/nucleos/usr/include x86; touch /home/devel/tmp/git/nucleos/usr/include/servers/.check
