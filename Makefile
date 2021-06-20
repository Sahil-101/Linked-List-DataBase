#This is makefile
.PHONY: clean 
testqueue: testlist.o linked_list.o
	gcc -g -Wall  -fno-omit-frame-pointer  linked_list.o testlist.o -o testlist

linked_list.o: linked_list.c linked_list.h 
	gcc -g -Wall -c linked_list.c

testlist.o: testlist.c linked_list.h
	gcc -g -Wall -c testlist.c

clean:
	rm  testlist linked_list.o  testlist.o
