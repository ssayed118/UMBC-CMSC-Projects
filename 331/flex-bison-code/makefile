#command to call this make file: make -f mymake-flex thermo
FLEX = flex 
BISON = bison -d -v -o y.tab.c
CC = cc

#therm is the target to build the application executable
thermo: y.tab.o lex.yy.o controller.o
	$(CC) -o thermo y.tab.o lex.yy.o controller.o 

# The next dependency rule indicates that lex.yy.o depends on
# lex.yy.c and y.tab.h
# Make uses the dependencies to figure out what rules must be run when a file has changed.

lex.yy.o: lex.yy.c y.tab.h

controller.o: controller.c y.tab.h

y.tab.c y.tab.h: parser.y
	$(BISON) parser.y

lex.yy.c: tokenizer.l
	$(FLEX) tokenizer.l

#To remove files in build directory: make -f mymake-flex clean

clean:
	-rm -f *.o lex.yy.c *.tab.*  thermo *.out*

