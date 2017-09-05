#include "stdlib.h"
#include "linked_list.h"


void linked_list_init(LinkedList* list, void(*destroy)(void* data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}


void linked_list_destroy(LinkedList* list) {
    void* data;
    while (linked_list_size(list)>0) {
        int x = linked_list_remove_next(list, NULL, (void**)&data);
        if (x == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
}


/**
* insert an element just after **element** in the linked list specified by **list**
* the new element contains a pointer to **data** , so the memory referenced by **data** should remain valid as long as the element remains in the list
* @return 0 if the inserting is successful , or -1 otherwise
*/
int linked_list_insert_next(LinkedList* list, LinkedListElement* element, const void* data) {
    LinkedListElement *new_element = (LinkedListElement*)malloc(sizeof(LinkedListElement));
    if (new_element == NULL) {
        return -1;
    }

    new_element->data = (void*)data;
    if (element == NULL) {
        if (linked_list_size(list) == 0) {
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;
    }
    else {
        if (element->next == NULL) {
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}



/**
* remove the next element of certain element , and save the data pointer of the removing element to the `data` param.
* it's the caller's responsibilty to manage the storage associated with the data
* @param {element} LinkedListElement ,if NULL, remove the first
* @return 0 if the removing is successful , or -1 otherwise
*/
int linked_list_remove_next(LinkedList* list, LinkedListElement* element, void** data) {
    if (linked_list_size(list) == 0) {
        return -1;
    }

    LinkedListElement *old_element;
    if (element == NULL) {

        // save the old data pointer to *data for the caller to manage the storage 
        *data = list->head->data;

        old_element = list->head;
        list->head = list->head->next;

        if (linked_list_size(list) == 1) {
            list->tail = NULL;
        }

    }
    else {

        if (element->next == NULL) {
            return -1;
        }

        // save the old data *pointer to *data for the caller to manage the storage 
        *data = element->next->data;

        old_element = element->next;
        element->next = element->next->next;

        if (element->next == NULL) {
            list->tail = element;
        }

    }

    free(old_element);
    list->size--;
    return 0;
}