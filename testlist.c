/*
   
 Made By prathamesh desai 
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
	testLinsert();
	//testLdelete();
	printf("All test passed\n");
	return 0;
}

void testLinsert()
{
	printf("testing Linsert function\n");
	List newlist = Lmakelist();
	assert(Lisempty(newlist) == 1);
	Linsert(newlist, "akash","65464544","a;sdjdf;kdf");
	assert(Lisempty(newlist) == 0);
	Linsert(newlist,"prathax","213123","2312323");
	assert(Lisempty(newlist) == 0);
	Linsert(newlist, "sahil","23123","1232312");
	assert(Lisempty(newlist) == 0);
	Lprintlist(newlist);
	Lfree(newlist);
	printf("test passed \n");
}

/*
void testLdelete()
{
	printf("testing Ldelete function\n");
	List newlist2 = Lmakelist();
	assert(Lisempty(newlist2) == 1);

	//case-1 when list is of only 1 element
	Linsert(newlist2, 3);
	Ldelete(newlist2, 3);
	assert(Lsize(newlist2) == 0);
	Lprintlist(newlist2);

	//case-2 deleteing last element
	Linsert(newlist2, 1);
	Linsert(newlist2, 2);
	Linsert(newlist2, 3);
	Linsert(newlist2, 4);
	Lsize(newlist2) == 4;
	Lprintlist(newlist2);
	Ldelete(newlist2, 4);
	Lsize(newlist2) == 3;
	Lprintlist(newlist2);

	//case3 deleteing in between
	Ldelete(newlist2, 2);
	assert(Lsize(newlist2) == 2);
	Lprintlist(newlist2);

	//random deleting
	Ldelete(newlist2, 2);
	Ldelete(newlist2, 1);
	Ldelete(newlist2, 3);
	assert(Lsize(newlist2) == 0);
	Lfree(newlist2);
	printf("test passed \n");
}
*/
