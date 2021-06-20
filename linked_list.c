/*    
 Made By prathamesh desai
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
	Node newnode = malloc(sizeof(newnode));
	assert(newnode != NULL);
	
    newnode->value = val;
    newnode->phone=phoneNum;
	newnode->name = userName;
    newnode->email= email;
    newnode->next = NULL;
    printf("agla null hai bahi\n");
    val++;
    
	return newnode;
}

//Creates a node for linked list
List Lmakelist()
{
	List Llist = malloc(sizeof(Llist));
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
	if (list->head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		Node curr = list->head;
		while (curr != NULL)
		{

			printf("%d/n", curr->value);
            printf("%s is name/n", curr->name);
            printf("%s is email/n", curr->email);
            printf("%s is phone numer", curr->phone);
 
			curr = curr->next;
		}
		printf("\n");
	}
}

//Remove the given element from Linked list
void Ldelete(List list, int val)
{
	assert(list != NULL);
	if (list->size == 0)
	{
		printf("cannot delete from empty list\n");
		assert(list->size != 0);
	}
	else if (list->size == 1)
	{
		if (list->head->value == val)
		{
			free(list->head);
			list->head = NULL;
			list->size--;
			return;
		}
		else
		{
			printf("no such element found\n");
			assert(list->head->value == val);
		}
	}
	else if (list->head->value == val)
	{   
		Node temp = list->head;
		list->head = list->head->next;
		free(temp);
        Node temp2 = list->head;
        while(temp2->next!=NULL)
        {
                  temp2->value--;
                  temp2 = temp->next;
        }
		list->size--;
        free(temp2);
		return;
	}
	else
	{
		Node bfcurr = NULL;
		Node curr = list->head;

		while (curr->value != val)
		{
			bfcurr = curr;
			curr = curr->next;
			if (curr == NULL)
			{
				printf("no such element found\n");
				return;
			}
		}

		if (curr->next == NULL)
		{
			Node temp = bfcurr->next;
			bfcurr->next = NULL;
			
            free(temp);
			list->size--;
			return;
		}
		Node temp = bfcurr->next;
		bfcurr->next = curr->next;
		Node temp2 = curr->next;
        list->size--;
        while(temp2->next!=NULL)
        {
            temp2->value--;
            temp2=temp2->next;

        }
        temp2->value--;
        free(temp2);
        free(temp);

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
