#include "linked_list.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"



void destroy(void* s) {
    return;
}


void main(int argc, char* argv[]) {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

    typedef void(*DestroyItem)();
    DestroyItem destroy_item = destroy;

    linked_list_init(list, destroy_item);

        void* data;
        LinkedListElement *current;

        data = "xxxx";
        current= linked_list_tail(list);
        linked_list_insert_next(list, NULL, data);

        data = "yyyy";
        current= linked_list_tail(list);
        linked_list_insert_next(list, NULL, data);

        data = "zzz";
        current= linked_list_tail(list);
        linked_list_insert_next(list, NULL, data);

    LinkedListElement *element = list->head;
    if (element == NULL) {
        printf("error");
        return;
    }
    do {
        char* x = (char *)(element->data);
        printf("::%s\r\n", x);
        element = linked_list_next(element);
    } while (element != NULL);

    free(list);
    getchar();
    return;
}

