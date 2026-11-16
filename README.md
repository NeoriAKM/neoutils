![C](https://img.shields.io/badge/C-99-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)
![Last commit](https://img.shields.io/github/last-commit/NeoriAKM/qalam?color=red)
![License](https://img.shields.io/badge/Last_README_update-15.11.2026-green)

# Neoutils 2.0

Insanely simple **coreutils**, written on **C**. Contains **10** utils, but large - only 1-3.

## Utils

| utilito | input | output |
|:-------:|:-----:|:------:|
| lsdr | dirname | files in this dir |
| dog | filename | file content (lines) |
| echo | string | outs this string | - |
| false & true | - | returns true or false |
| myname | - | out user name | - |
| sleep | time (in int) | freezing console for [n] seconds |
| yes | yyyyyy | yyyyyy |
| wai | - | out user directory |

And about flags you can read on lauch program. But if program has no flags, nothing will hapenned

## Build

```sh
cmake -B build # once
cmake --build build -j2 # build utils
# moves executable to /usr/bin
sudo cmake --install build
```

## run

Type a command name *(example: `lsdr` or `yes`)*. It will run, because `sudo cmake --install build` moving executable files to `/usr/bin`

---

<div align="center">
    Made by
    <a href="https://github.com/neoriakm" style="color: cyan;">NeoriAKM</a>
    For
    <a href="https://github.com/progwi0"  style="color: lime;">Progwi0</a>
</div>