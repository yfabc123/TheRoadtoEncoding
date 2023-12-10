CC:=gcc
INCLUDE_DIR:= -I ${shell pwd}/include
OBJECT_DIR:=${shell pwd}/obj
SUB_DIR:=fun global main obj
BIN_DIR:=${shell pwd}/bin
TARGET:=exec
.PHONY:all $(SUB_DIR)
export CC INCLUDE_DIR OBJECT_DIR SUB_DIR BIN_DIR TARGET

# all:
# 	mkdir -p bin
# 	$(foreach dir,$(SUB_DIR),make -C $(dir);)

all:$(SUB_DIR)
$(SUB_DIR):
	mkdir -p bin
	make -C $@

clean:
	rm -rf ./bin ./obj/*.o
