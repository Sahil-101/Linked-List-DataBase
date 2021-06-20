/*    
 Made By Sahil
 main fxn file for Linked-list adt adt
 
 Date-2/Aug/20

 ALL RIGHTS RESERVED
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

#define TRUE 1
#define FALSE 0

typedef struct node *Node;

int val=1;

struct Slist
{
	Node head;
	int size;
};

struct node
{
    int value;
    char *name;
    char *phone;
    char *email;
	Node next;
};

//Private function to make nodes
static Node makenode(char *userName,char *phoneNum,char* email)
{
	Node newnode = malloc(sizeof(*newnode));
	assert(newnode != NULL);
	
    newnode->value = val;
    newnode->phone=phoneNum;
	newnode->name = userName;
    newnode->email= email;
    newnode->next = NULL;
    
    val++;
    
	return newnode;
}

//Creates a node for linked list
List Lmakelist()
{
	List Llist = malloc(sizeof(struct Slist));
	assert(Llist != NULL);
	Llist->head = NULL;
	Llist->size = 0;
	return Llist;
}

//Add item at end of the linked list
void Linsert(List list,char *userName,char *phoneNum,char* email)
{
	Node node = makenode(userName,phoneNum,email);
	assert(node != NULL);
	if (list->size == 0)
	{
		list->head = node;
		list->size++;
        return;
	}
	else
	{
		Node curr = list->head;
		
        for(int i = 0;i<list->size-1;i++)
        {
            curr=curr->next;   
        }
        
        curr->next = node;
		list->size++;
	}
}

//Returns and pritns size of list
int Lsize(List list)
{
	assert(list != NULL);
	return list->size;
}

//Returns true if empty else false
int Lisempty(List list)
{
	assert(list != NULL);
	if (list->size == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//prints content of the list
void Lprintlist(List list)
{
	assert(list != NULL);
	if (list->size==0)
	{
		printf("List is empty\n\n\n");
	}
	else
	{
		Node curr = list->head;
		while(curr!=NULL)
		{

			printf("%d is value\n", curr->value);
            printf("%s is name\n", curr->name);
            // printf("%s is email\n", curr->email);
            // printf("%s is phone numer\n", curr->phone);
 
			curr = curr->next;
		}		
		printf("\n\n\n");
	}
}

//Remove the given element from Linked list
void Ldelete(List list, int vals)
{
	if(list->head==NULL)
		printf("list is not made\n");
	if(list->size==0)
		printf("list empty\n");
	Node temp,temp2;
	if(list->head->value==vals)
	{
		temp=list->head;
		list->head=temp->next;
		free(temp);
		temp=list->head;
		val--;
		list->size--;
		for(int i=0; i< (list->size) ; i++)
		{
			temp->value--;
			temp=temp->next;
		}	
		return;
	}

	
	temp=list->head;
	temp2=list->head;

	while(temp->next!=NULL && temp->value!=vals)
	{
		temp2=temp;
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		if (temp->value == vals)
		{
			free(temp);
			temp2->next=NULL;
			list->size--;
			val--;
			return;
		}
		else
		{
			printf("Not found given element");
		}
	}
	else 
	{
		temp2->next=temp->next;
		temp2=temp;
		while(temp2!=NULL)
		{
			temp2->value--;
			temp2=temp2->next;
		}
		free(temp);
		list->size--;
		val--;
		return;
	}
	
}

//Frees the dynamically allocated memory
void Lfree(List list)
{
	assert(list != NULL);
	if (list->size == 0)
	{
		free(list);
	}
	else
	{
		Node curr, bfcurr;
		bfcurr = NULL;
		curr = list->head;
		while (curr != NULL)
		{
			bfcurr = curr;
			curr = curr->next;
			free(bfcurr);
		}

		free(list);
	}
}
