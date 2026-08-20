alias cm='gcc -Os -s -ffunction-sections -fdata-sections -Wl,--gc-sections'

if [[ ! "$1" ]]; then

    # dinamic
    echo "DINAMIC COMPILATION"

    cm src/lsdr.c -o files/lsdr         && echo "(dn) lsdr:     OK"
    cm src/dog.c -o files/dog           && echo "(dn) dog:      OK"
    cm src/whereami.c -o files/whereami && echo "(dn) whereami: OK"
    cm src/echo.c -o files/echo         && echo "(dn) echo:     OK"
    cm src/clear.c -o files/clear       && echo "(dn) clear:    OK"
    cm src/wait.c -o files/wait         && echo "(dn) wait:     OK"
    cm src/yes.c -o files/yes           && echo "(dn) yes:      OK"
    cm src/yesno.c -o files/yesno       && echo "(dn) yesno:    OK"
    cm src/mov.c -o files/mov           && echo "(dn) mov:      OK"

    # static
    echo ""
    echo "STATIC COMPILATION"

    cm -static src/lsdr.c -o static/lsdr         && echo "(st) lsdr:     OK"
    cm -static src/dog.c -o static/dog           && echo "(st) dog:      OK"     
    cm -static src/whereami.c -o static/whereami && echo "(st) whereami: OK"
    cm -static src/echo.c -o static/echo         && echo "(st) echo:     OK"
    cm -static src/clear.c -o static/clear       && echo "(st) clear:    OK"
    cm -static src/wait.c -o static/wait         && echo "(st) wait:     OK"
    cm -static src/yes.c -o static/yes           && echo "(st) yes:      OK"
    cm -static src/yesno.c -o static/yesno       && echo "(st) yesno:    OK"
    cm -static src/mov.c -o static/mov           && echo "(st) mov:      OK"


    # ZIP archivation
    echo ""
    echo "MAKING ZIP"

    zip -r src/all.zip src/*       -x src/all.zip    src/touch.c
    zip -r files/all.zip files/*   -x files/all.zip  files/touch
    zip -r static/all.zip static/* -x static/all.zip static/touch

else
    if [[ "$1" = "zip" ]]; then
        zip -r src/all.zip src/*       -x src/all.zip    src/touch.c
        zip -r files/all.zip files/*   -x files/all.zip  files/touch
        zip -r static/all.zip static/* -x static/all.zip static/touch
    else
        echo "compiling $1..."
        cm src/$1.c -o files/$1 && echo "(dn) success"
        cm -static src/$1.c -o static/$1 && echo "(st) success"
    fi
fi