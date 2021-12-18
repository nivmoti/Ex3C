FLAG=-Wall -g
CC=gcc


#targets:
all: StringProgs StringProgd stringProg
#names:
StringProgs:libclassStringProgs.a;
StringProgd: libclassStringProgd.so;
#main:
stringProg: main.o
	$(CC) $(FLAG) -o stringProg main.o ./libclassStringProgd.so -lm
#static library
libclassStringProgs.a: StringProg.o
		ar -rcs libclassStringProgs.a StringProg.o
libclassStringProgd.so: StringProg.o
		$(CC) -shared -o libclassStringProgd.so StringProg.o

#the order of function:
StringProg.o: StringProg.c my_StringProg.h
		$(CC) $(FLAG) -c StringProg.c 
main.o:main.c my_StringProg.h
	$(CC) $(FLAG) -c main.c 

.PHONY:clean
clean:
	rm -f *.o *.so stringProg