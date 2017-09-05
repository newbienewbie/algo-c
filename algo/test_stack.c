#include "stack.h"
#include "stdio.h"



static void destroy(void* data) {
    return;
}



void test_stack() {

    Stack *stack=(Stack*) malloc(sizeof(Stack));

    stack_init(stack,destroy);

    void* data;
    data= "+";
    stack_push(stack,data);
    data= "-";
    stack_push(stack,data);
    data= "*";
    stack_push(stack,data);

    while(1) {
        char x[100];
        void** itemPtr=x;
        data = stack_peek(stack);
        printf("%s\r\n",(char*)data);
        stack_pop(stack,itemPtr);
        if (stack_size(stack)==0) {
            break;
        }
    }

    stack_destroy(stack);
    getchar();
    return;
}