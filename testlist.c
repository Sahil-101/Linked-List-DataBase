/*
   
 Made by Sahil
 test  file for Linked List
 
 Date-2/aug/20

 ALL RIGHTS RESERVED

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

int main()
{
	//testLinsert();
	testLdelete();
	printf("All test passed\n");
	return 0;
}

void testLinsert()
{
	printf("testing Linsert function\n");
	List newlist = Lmakelist();
	assert(Lisempty(newlist));
	Linsert(newlist, "akash","65464544","a;sdjdf;kdf");
	assert(!Lisempty(newlist));
	Linsert(newlist,"prathax","213123","2312323");
	assert(!Lisempty(newlist));
	Linsert(newlist, "sahil","23123","1232312");
	assert(!Lisempty(newlist));
	Lprintlist(newlist);
	Lfree(newlist);
	printf("test passed \n");
}


void testLdelete()
{
	printf("testing Ldelete function\n");
	List newlist = Lmakelist();
	assert(Lisempty(newlist) == 1);

	//case-1 when list is of only 1 element
	Linsert(newlist, "sahil","23123","1232312");
	Ldelete(newlist,1);
	assert(Lsize(newlist) == 0);
	Lprintlist(newlist);

	//case-2 deleteing last element
	Linsert(newlist, "sahil","2","1");
	Linsert(newlist, "sahil1","23","12");
	Linsert(newlist, "sahil2","231","123");
	Linsert(newlist, "sahil3","2312","1232");
	assert(Lsize(newlist) == 4);
	Lprintlist(newlist);
	Ldelete(newlist, 1);
	assert(Lsize(newlist) == 3);
	Lprintlist(newlist);



	//case3 deleteing in between
	Ldelete(newlist, 2);
	assert(Lsize(newlist) == 2);
	Lprintlist(newlist);

	// //random deleting
	// Ldelete(newlist, 2);
	// Ldelete(newlist, 1);
	// Ldelete(newlist, 3);
	// assert(Lsize(newlist) == 0);
	Lfree(newlist);
	printf("test passed \n");
}
