cm() {
    gcc -Os -s -ffunction-sections -fdata-sections -Wl,--gc-sections "$@"
}

make_zip() {
    for d in src files static; do
        [[ -d "$d" ]] || continue
        (cd "$d" && zip -r all.zip . -x 'all.zip') >/dev/null
        echo "zip: $d/all.zip"
    done
}


UTILS=(lsdr dog whereami clear wait yes yesno mov add)

mkdir -p files static

if ! echo 'int main(void){return 0;}' | gcc -static -x c - -o /tmp/_t 2>/dev/null; then
    echo "warning: -static not supported, skipping static build"
    SKIP_STATIC=1
fi

if ! command -v zip >/dev/null; then
    echo "zip not found"
    SKIP_ZIP=1
fi


###################################################
###################################################
###################################################

if [[ $# -eq 0 ]]; then

    # dinamic
    echo "DINAMIC COMPILATION"

    for i in "${UTILS[@]}"; do
        cm src/$i.c -o files/$i && printf '(dn) %-15s OK\n' "$i:" || printf '(dn) %-15s FAIL\n' "$i:"
    done

    # static
    if [[ -z "${SKIP_STATIC:-}" ]]; then
        echo ""
        echo "STATIC COMPILATION"

        for i in "${UTILS[@]}"; do
            cm -static src/$i.c -o static/$i && printf "(st) %-15s OK\n" "$i:" || printf "(st) %-15s FAIL\n" "$i:"
        done
    fi

    # ZIP archivation
    if [[ -z "${SKIP_ZIP:-}" ]]; then
        echo ""
        echo "MAKING ZIP"
        make_zip
    fi

elif [[ "$1" = "zip" ]]; then
    make_zip
else

    echo "compiling $1..."
    cm src/$1.c -o files/$1 && echo "(dn) success" || echo "(dn) fail"
    if [[ -z "${SKIP_STATIC:-}" ]]; then
        cm -static src/$1.c -o static/$1 && echo "(st) success" || echo "(st) fail"
    fi
fi