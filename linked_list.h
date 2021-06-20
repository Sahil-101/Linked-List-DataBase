/*    
 Made By prathamesh desai
 interface file for queue adt
 
 Date-2/Aug/20

 ALL RIGHTS RESERVED
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Slist *List;

//Creates a node for linked list
List Lmakelist();

//Add item at end of the linked list
void Linsert(List list, char *userName,char *phoneNum,char *email);

//Remove the given element from Linked list
void Ldelete(List list, int val);

//Frees the dynamically allocated memory
void Lfree(List list);

//Returns true if empty else false
int Lisempty(List list);

//Returns and pritns size of list
int Lsize(List list);

//prints content of the list
void Lprintlist(List list);

#endif
