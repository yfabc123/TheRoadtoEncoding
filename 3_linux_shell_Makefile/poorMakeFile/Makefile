SUB_DIR :=main fun global  obj 
export SUB_DIR #设置为全局

TARGET: 
	mkdir -p ./bin
	$(foreach dir,$(SUB_DIR),make -C $(dir);)
clean:
	rm -rf ./bin ./obj/*.o