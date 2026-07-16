alias cm='gcc -Os -s -ffunction-sections -fdata-sections -Wl,--gc-sections'

# dinamic
cm src/lsdr.c -o files/lsdr
cm src/dog.c -o files/dog
cm src/whereami.c -o files/whereami
cm src/echo.c -o files/echo
cm src/clear.c -o files/clear
cm src/time.c -o files/time

# static
cm -static src/lsdr.c -o static/lsdr
cm -static src/dog.c -o static/dog
cm -static src/whereami.c -o static/whereami
cm -static src/echo.c -o static/echo
cm -static src/clear.c -o static/clear
cm -static src/time.c -o static/time