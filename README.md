# (EN) NeoUtils - simple Coreutils on C

**By:** NeoriGG
**Version:** 16.78
**License:** MIT

Utilities-pack, thats doing the same, whats a classic GNU CoreUtils. Something between GNU CoreUtils and BusyBox.
---
## Whats in the NeoUtils
### lsdr - analog of ls

I am rewrote classic command ls from scratch. She is shows files & folders in working directory
She is:

- Weight 6 KB (GNU ls — ~120 KB).
- Working **without** `stdio.h` & `string.h`.
- Using an own `printf` & `strcmp`.
- Have a many flags, about his I made **--help** for every command

#### ***Shows list fast and without trash. If you need balance functionality, weight and dependencies - this lsdr is your***
---
### dog - analog of cat

Yes, its dog. She's doing the same, whats thee cat. But... naming better :)
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
inside - own strlen, strcmp, printi, prints.

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

---
## Requirements
### OS
Linux or another UNIX-like OS is recommended. If `glibc` is missing, download the static binary.
### C Compiler
Any working compiler (though I recommend GCC for running `build.sh`).

## Installation

Download the ready-made files from the [NeoUtils website](https://neoriakm.github.io/neoutils).

---
---
---

# (RU) NeoUtils - минималистичный Coreutils на C

**Автор:** NeoriGG
**Версия:** 16.78
**Лицензия:** MIT

Набор утилит, которые делают то же самое, что и стандартные GNU Coreutils. Что то между GNU CoreUtils и BusyBox.

---
## Что внутри NeoUtils
### lsdr - аналог ls

Я переписал классическую команду ls с нуля. Она показывает файлы и папки в текущей директории.
В отличие от оригинала, она:

- Весит 6 КБ (GNU ls — ~120 КБ).
- Работает **без** `stdio.h` & `string.h`.
- Использует собственный `printf` & `strcmp`.
- Имеет дофига флагов, о которых красиво показано в **--help**

#### ***Показывает список быстро и без мусора. Если вам нужен баланс функциональности, веса и зависимостей — этот lsdr будет в самый раз.***
---
### dog - аналог cat

Да, это собака. Она делает то же, что и cat, но называется лучше.
Выводит содержимое файлов.
Используется просто:

```bash
dog file.txt
```

Ничего, всё по делу. Работает быстро, весит копейки, много флагов:
- --help & --version : база
- -n : отключает нумерацию
- -e : пропускает пустые строки
- -a : убирает ограничение в 500 строк
---
### whereami - аналог pwd

Показывает, в какой папке вы сейчас находитесь. Полный путь до текущей директории.
Команда настолько простая, что я даже не стал перегружать её флагами.
Есть только --help и --version - куда без них.

Для простоты, можете сделать **алиас** `whereami='wai'`

---
### echo - аналог echo

Выводит переданный текст в терминал.
Работает как обычно:

```bash
echo Привет, мир!
# вывод: Привет, мир!
```
Никаких флагов, ничего нету. Просто печатает то, что вы ему скажете.
Внутри - свой strlen, strcmp, printi, prints.

---
### clear - аналог clear

Очищает экран терминала.
Всё. Просто очищает.

---
### time - таймер для скриптов (аналог sleep)

Эта утилита родилась из потребности делать паузы в скриптах.
Она не выводит время как date, она ждёт заданное количество времени и выходит.

Поддерживает флаги:
- -s : число в секундах
- -m : число в минутах
- -u : число в микросекундах

Например:
```bash
time -s 5   # подождать 5 секунд
time -m 1   # подождать 1 минуту
```
Идеально для скриптов, где нужно поставить задержку.

---
## Требования
### ОС
Рекомендуется linux или другая UNIX-подобная ОС. Если нету `glibc` - скачивайте static-файл
### Компилятор C
Любой, главное рабочий (Но для запуска `build.sh` я бы рекомендовал GCC)

## Установка

Скачай готовые файлы с [сайта NeoUtils](https://neoriakm.github.io/neoutils).