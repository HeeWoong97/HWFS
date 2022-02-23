a.out :	llist.o dir.o main.o
	gcc -o a.out llist.o dir.o main.o

llist.o : llist.c
	gcc -c llist.c

dir.o : dir.c
	gcc -c dir.c

main.o : main.c
	gcc -c main.c

clean :
	rm *.o a.out