a.out :	llist.o dir.o file.o main.o
	gcc -o a.out llist.o dir.o file.o main.o

llist.o : llist.c
	gcc -c llist.c

dir.o : dir.c
	gcc -c dir.c

file.o : file.c
	gcc -c file.c

main.o : main.c
	gcc -c main.c

clean :
	rm *.o a.out
