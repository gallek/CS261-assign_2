/*
 * This is the file in which you'll write the functions required to implement
 * a queue using two stacks.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name:
 * Email:
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "queue_from_stacks.h"

/*
 * This function should allocate and initialize all of the memory needed for
 * your queue and return a pointer to the queue structure.
 */
struct queue_from_stacks* queue_from_stacks_create() {
 	struct queue_from_stacks* q = malloc(sizeof(*q)); //creates an object that holds 2 structs will appropriately allocated memory
	q->s1=stack_create(); //create a first empty stack with a pointer returned to it
	q->s2=stack_create(); //creates a second empty stack with a pointer returned to it
	return q;
}	

/*
 * This function should free all of the memory allocated to a queue, including
 * the memory associated with each stack.
 *
 * Params:
 *   queue - the queue to be destroyed.  May not be NULL.  The function should
 *     exit the program with an error if queue is NULL.
 */
void queue_from_stacks_free(struct queue_from_stacks* queue) {
	assert(queue);
	stack_free(queue->s1);
	stack_free(queue->s2);
	free(queue);
}

/*
 * This function should return 0 if a queue is completely empty or 1 if there
 * is at least one element stored in the queue.
 *
 * Params:
 *   queue - the queue whose emptiness is to be checked.  May not be NULL.
 *     The function should exit the program with an error if queue is NULL.
 *
 * Return:
 *   Should return 1 if the queue is empty or 0 otherwise.
 */
int queue_from_stacks_isempty(struct queue_from_stacks* queue) {
  	assert(queue); //makes sure an error is thrown if NULL
	int x=0;
	int y=0;
	x=stack_isempty(queue->s1); //checks if s1 is empty
	y=stack_isempty(queue->s2); //checks if s2 is empty
	if(x==1 && y==1){ 
		return 1; //if both are empty, return 1 because empty is true
	}
	else{
		return 0; //if any of them have elements within them, empty is false for the whole queue
	}
}

/*
 * Should enqueue a new value onto the end of a queue.
 *
 * Params:
 *   queue - the queue onto which to enqueue a value.  May not be NULL.
 *     The function should exit the program with an error if queue is NULL.
 *   value - the new value to be enqueueed onto the queue
 */
void queue_from_stacks_enqueue(struct queue_from_stacks* queue, int value) {
	assert(queue);
	while(!stack_isempty(queue->s1)){ //takes the elements from s1 and puts them into s2
		stack_push(queue->s2, stack_top(queue->s1)); //makes sure the oldest entered element is always at the top of the stack
		stack_pop(queue->s1);
	}
	stack_push(queue->s1, value); //pushes the value into s1
	while(!stack_isempty(queue->s2)){ //takes the elements from s2 and puts them back into s1
		stack_push(queue->s1, stack_top(queue->s2)); ////makes sure the oldest entered element is always at the top of the stack
                stack_pop(queue->s2);
	}
}

/*
 * Should return a queue's front value without removing that value from the
 * queue.
 *
 * Params:
 *   queue - the queue from which to read the front value.  May not be NULL or
 *     empty.  The function should exit the program with an error if queue is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the front of the queue.
 */
int queue_from_stacks_front(struct queue_from_stacks* queue) {
  	assert(queue); //makes sure an error will be thrown if NULL
	int x; 
	x=stack_top(queue->s1); //stores the top value from stack 1
	return x; //returns that value to fill the front value section of the test
}

/*
 * Should remove the front element from a queue and return its value.
 *
 * Params:
 *   queue - the queue from which to dequeue a value.  May not be NULL or
 *     empty.  The function should exit the program with an error if queue is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the front of the queue before that value
 *   is dequeued.
 */
int queue_from_stacks_dequeue(struct queue_from_stacks* queue) {
	assert(queue); //makes sure an error will be thrown if NULL
	int x;
	x=stack_pop(queue->s1); //dequeue can just pop from stack 1 
	return x; //pop an item from s1 and return that value because enqueue function made sure the oldest element is at the top of the stack
}
