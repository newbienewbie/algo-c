#pragma once

#include "linked_list.h"

typedef LinkedList Stack;

#define stack_init linked_list_init

#define stack_destroy linked_list_destroy

int stack_push(Stack* stack,const void *data);
int stack_pop(Stack* stack, void **data);

#define stack_peek(stack)  ((stack)->head==NULL? NULL: (stack)->head->data)

#define stack_size linked_list_size

