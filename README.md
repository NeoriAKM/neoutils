![C](https://img.shields.io/badge/C-99-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)
![Last commit](https://img.shields.io/github/last-commit/NeoriAKM/qalam?color=red)
![License](https://img.shields.io/badge/Last_README_update-15.11.2026-green)

# Neoutils 2.0


Insanely simple **coreutils**, written on **C**. Contains only 1 util - lsdr.

## Build

```sh
cmake -B build # once
cmake --build build -j2 # build utils
# moves executable to /usr/bin
sudo cmake --install build
```

## run

Type a command name *(example: `lsdr`)*. It will run, because `sudo cmake --install build` moving executable files to `/usr/bin`

---

<div align="center">
    Made by
    <a href="https://github.com/neoriakm" style="color: cyan;">NeoriAKM</a>
    For
    <a href="https://github.com/progwi0"  style="color: lime;">Progwi0</a>
</div>