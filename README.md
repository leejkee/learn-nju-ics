## The display of number 0~9 in simulated digital tube
This program is an extension of an example from [nju-ics course](https://nju-projectn.github.io/ics-pa-gitbook/ics2023/)  
- This repo `src/led.c` completes the display of number zero to nine.
- The simulated digital tube: `python_files/display.py`, it's from the ics course
- The `src/logic.c` implements the cyclic display of numbers 0 to 3, it's from the ics course

### requirement
These work in archlinux x64 only, if you use other OS or platform, just search the web.

- python3 and tk (**`tk`** is required to run display.py)
```shell
sudo pacman -Sy python3 tk
```

### how to run
#### cmake
if you use Archlinux, just run `sudo pacman -S cmake` to install cmake 
And then, run:
```shell
cmake -B build
cmake --build build
build/Main | python python_files/display.py
```

or you can also use **`Visual Studio Code`** with its cmake extensions.  
_*tips: The `AUR` repo is required if you want to install vscode in archlinux, just add it to your `pacman.conf`, then you can run `yay -S visual-studio-code-bin` to install it.*_


#### makefile
run:
```shell
make run
```

## to be continue