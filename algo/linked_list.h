#pragma once
#pragma once


#include "stdlib.h"


typedef struct LinkedListElement_ {
	void * data;
	struct LinkedListElement_ *next;
} LinkedListElement;


typedef struct LinkedList_ {
	int size;
	int(*match)(const void* key1, const void* key2);
	void(*destroy)(void* data);

	LinkedListElement *head;
	LinkedListElement *tail;
} LinkedList;


void linked_list_init(LinkedList* list, void(*destroy)(void* data));

void linked_list_destroy(LinkedList* list);


int linked_list_insert_next(LinkedList* list, LinkedListElement* element, const void* data);

int linked_list_remove_next(LinkedList* list, LinkedListElement* element, void** data);

#define linked_list_size(list) ((list)->size)

#define linked_list_head(list) ((list)->head)

#define linked_list_tail(list) ((list)->tail)

#define linked_list_is_head(list,element) ((element)==(list)->head? 1:0)

#define linked_list_is_tail(element) ((element)->next == NULL ? 1:0)

#define linked_list_data(element) ((element)->data)

#define linked_list_next(element) ((element)->next)