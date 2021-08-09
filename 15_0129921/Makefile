#OBJS specifies which files to compile as part of the project
FLEX_OBJS = src/*.l
C_OBJS = *.c

#FLEX specifies flex
FLEX = flex

#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall

#OBJ_NAME specifies the name of our executable
OBJ_NAME = tradutor

#This is the target that compiles our executable
all:
	$(FLEX) $(FLEX_OBJS); \
	$(CC) $(C_OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) \