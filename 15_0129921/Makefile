#OBJS specifies which files to compile as part of the project
BISON_OBJS = src/*.y
FLEX_OBJS = src/*.l
C_OBJS = src/*.c

#BISON specifies bison
BISON = bison

#FLEX specifies flex
FLEX = flex

#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -Ilib/

#OBJ_NAME specifies the name of our executable
OBJ_NAME = tradutor

#This is the target that compiles our executable
all:
	$(BISON) -d -o src/syn.tab.c $(BISON_OBJS); \
	$(FLEX) --outfile=src/lex.yy.c $(FLEX_OBJS); \
	$(CC) $(C_OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) \