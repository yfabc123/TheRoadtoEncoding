SRC:=$(wildcard ./*.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))

all:$(OBJ)

$(OBJ):$(SRC)
	$(CC) $(INCLUDE_DIR) -c $^ -o $(OBJECT_DIR)/$@


