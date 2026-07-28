# (EN) NeoUtils - simple Coreutils on C

**By:** NeoriGG
**Version:** 28.78
**License:** INLv1

Utilities-pack, thats doing the same, whats a classic GNU CoreUtils. Something between GNU CoreUtils and BusyBox.
---
## Whats in the NeoUtils
### lsdr - analog of ls

I am rewrote classic command ls from scratch. She is shows files & folders in working directory
She is:

- Weight 15 KB (GNU ls — ~162 KB).
- Working **without** `stdio.h` & `string.h`. Only `unistd.h`
- Using an own `prints` & `strcmp`.
- Have a many flags, about his I made **--help** for every command

#### ***If you need balance functionality, weight and dependencies - this lsdr is your***
---
### dog - analog of cat

dog - is an analog of cat, but with additions
Typing a file content
simple in using:

```bash
dog file.txt
```

Working fast, weight a small, many flags:
- --help & --version : base
- -n : disabling numeration
- -e : skip empty stringlines
- -a : disabling limit in 500 stringlines
---
### whereami - analog of pwd

It shows which folder you are currently in the full path to the current directory.
The command is so simple that I didn't even clutter it with flags.
There are only `--help` and `--version`, you can't do without those.

For simplicity, you can create an alias: `whereami='wai'`

---
### echo - analog of echo

Typing transmitted text.
Working an usual:

```bash
echo Hello, world!
# output: Hello, world!
```
It's... just typing. Yes.
inside - own strlen, strcmp, prints.
I tryed add flags, but... I can't

---
### clear - analog of clear

clearing terminal screen.
Its all. Just clearing.

---
### time - timer for srcipts (analog of sleep)

Thats utilite was born in needness doing a pauses in scripts.
It does not output the time like `date`; it waits for the specified amount of time and then exits.

flags:
- -s : number in seconds
- -m : number in minutes
- -u : number in microseconds

Work:
```bash
time -s 5   # wait 5 seconds
time -m 1   # wait 1 minute
```
Idealy for scripts, where you need a delay

---
## Requirements
### OS
Linux or another UNIX-like OS is recommended. If `glibc` is missing, download the static binary.
### C Compiler
Any working compiler (though I recommend GCC for running `build.sh`).

## Installation

Download the ready-made files from the [NeoUtils website](https://neoriakm.github.io/neoutils).

Files aviable in the [NeoUtils](https://neoriakm.github.io/neoutils) site. Static builds, if you haven't `glibc`, and dinamic, if have, but you want tosave few hundred KiB