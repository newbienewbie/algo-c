#include "stack.h"
#include "stdlib.h"


int stack_push(Stack * stack, const void * data)
{
    return linked_list_insert_next(stack,NULL,data);
}

int stack_pop(Stack * stack, void ** data)
{
    return linked_list_remove_next(stack,NULL,data);
}
