/*
 * This is the file in which you'll write a function to reverse a linked list.
 * Make sure to add your name and @oregonstate.edu email address below:
 *
 * Name:
 * Email:
 */

#include <stdio.h>

#include "list_reverse.h"

/*
 * In this function, you will be passed the head of a singly-linked list, and
 * you should reverse the linked list and return the new head.  The reversal
 * must be done in place, and you may not allocate any new memory in this
 * function.
 *
 * Params:
 *   head - the head of a singly-linked list to be reversed
 *
 * Return:
 *   Should return the new head of the reversed list.  If head is NULL, this
 *   function should return NULL.
 */
struct link* list_reverse(struct link* head) {
 	struct link* previous=NULL; //set to NULL so that the function ultimately returns NULL if the head is NULL
	while(head){ //while the linked list is not NULL (while true)
		struct link* current=head; //makes current hold the data stored in head
		head = head->next; //stores the next value
		current->next=previous; //reverses the current node's pointer value
		previous=current; //moves pointer a position ahead
	}
	return previous;
}
