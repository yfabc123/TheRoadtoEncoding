.PHONY : clean
CC = gcc
SRC = $(wildcard *.c)
OBJ = main.o fun.o
exec : $(OBJ)
	$(CC) $(OBJ) -o exec
%.o : %.c
	$(CC) -c $< -o $@
# $(OBJ):$(SRC)
# 	$(CC) -c $< -o $@
clean :
	rm -rf *.o exec
