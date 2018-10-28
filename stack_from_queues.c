/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name:
 * Email:
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"
#include "stack_from_queues.h"


/*
 * This function should allocate and initialize all of the memory needed for
 * your stack and return a pointer to the stack structure.
 */
struct stack_from_queues* stack_from_queues_create() {
  	struct stack_from_queues* s= malloc(sizeof(struct stack_from_queues)); //makes sure enough memory is allocated for the overall stack structure made up of queues
	s->q1=queue_create(); //creates first queue
	s->q2=queue_create(); //creates second queue
	return s; //returns the pointer to the overall stack structure
}

/*
 * This function should free all of the memory allocated to a stack, including
 * the memory associated with each queue.
 *
 * Params:
 *   stack - the stack to be destroyed.  May not be NULL.  The function should
 *     exit the program with an error if stack is NULL.
 */
void stack_from_queues_free(struct stack_from_queues* stack) {
	assert(stack); //makes sure that an error will be thrown if NULL
	queue_free(stack->q1);
	queue_free(stack->q2);
	free(stack);
}

/*
 * This function should return 0 if a stack is completely empty or 1 if there
 * is at least one element stored in the stack.
 *
 * Params:
 *   stack - the stack whose emptiness is to be checked.  May not be NULL.
 *     The function should exit the program with an error if stack is NULL.
 *
 * Return:
 *   Should return 1 if the stack is empty or 0 otherwise.
 */
int stack_from_queues_isempty(struct stack_from_queues* stack) {
  	assert(stack); //makes sure an error is thrown if NULL
	int x=0;
        int y=0;
        x=queue_isempty(stack->q1); //checks if q1 is empty
	y=queue_isempty(stack->q2); //checks if q2 is empty
	if(x==1 && y==1){
                return 1; //if both are empty, return 1 because empty is true
	}
	else{
		return 0; //if any of them have elements within them, empty is false for the whole stack
	}
}

/*
 * Should push a new value onto a stack.
 *
 * Params:
 *   stack - the stack onto which to push a value.  May not be NULL.
 *     The function should exit the program with an error if stack is NULL.
 *   value - the new value to be pushed onto the stack
 */
void stack_from_queues_push(struct stack_from_queues* stack, int value) {
	assert(stack);
	queue_enqueue(stack->q2, value); //first add to the q2 so we can then copy from q2 (adds the value into q2)
	while(!queue_isempty(stack->q1)){
		queue_enqueue(stack->q2, queue_dequeue(stack->q1)); //adds element to front from q1 into q2, removes from q1, makes sure that values are not being repeated because they are being removed from q1 (so q1 doesn't hold the same vlaue twice)
	}
	struct queue* temp; //makes a temporary queue so that the names can be switched
	temp=stack->q1; // don't need to keep track of which queue has the data in it and which does not, so swapping makes this simpler
	stack->q1=stack->q2; //now q1 holds q2 values
	stack->q2=temp; //q2 gets old q1 values
}

/*
 * Should return a stack's top value without removing that value from the
 * stack.
 *
 * Params:
 *   stack - the stack from which to read the top value.  May not be NULL or
 *     empty.  The function should exit the program with an error if stack is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the top of the stack.
 */
int stack_from_queues_top(struct stack_from_queues* stack) {
  	assert(stack);
	int x; 
	x=queue_front(stack->q1);
	return x; //fills the front value 
}

/*
 * Should remove the top element from a stack and return its value.
 *
 * Params:
 *   stack - the stack from which to pop a value.  May not be NULL or
 *     empty.  The function should exit the program with an error if stack is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the top of the stack before that value
 *   is popped.
 */
int stack_from_queues_pop(struct stack_from_queues* stack) {
	assert(stack); //makes sure that the queue is not NULL, otherwise this would not work
	return queue_dequeue(stack->q1); //pop function is not expensive because we just need to remove the item from the primary and return it
}
