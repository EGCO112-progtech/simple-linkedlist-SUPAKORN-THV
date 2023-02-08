DESP = ll
compile: main.c 
	 gcc main.c -o $(DESP)

run: $(DESP)
	 ./$(DESP)

clean: $(DESP)
	 rm $(DESP)
