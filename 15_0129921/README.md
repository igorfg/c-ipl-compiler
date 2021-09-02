# c-ipl-compiler
A Makefile is provided inside the main directory. 
```
$ make
```
In case you can't use make you can use the following commands from the main directory:
```
  $ bison -d -o src/syn.tab.c src/*.y; \
    flex --outfile=src/lex.yy.c src/*.l; \
    gcc src/*.c -Wall -Ilib/  -o tradutor \
```
In order to execute any of the example files run:
```
  $ ./tradutor < tests/chosen_example.c
```
In case you still can't compile anything, the executable file is provided inside the main directory as well.
