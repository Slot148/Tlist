#ifndef T_LIST
#define T_LIST

#include <stddef.h>
#include <stdbool.h>

/** @public */
typedef enum Type{
    T,     
    INT,    
    STRING,
    FLOAT, 
    DOUBLE
} Type;

typedef struct List *List;
typedef struct ArrayList *ArrayList;
typedef struct Node *Node;
typedef struct TIterator* TIterator;

//inicializadores
List new_list(Type type);
TIterator new_iterator(List list);

//linked list
void list_print(List this);
void list_push(List this, ...);
int list_length(List this);
void list_free(List this);
void *list_pop(List this);
void *list_get(List this, int index);
void list_set(List this, int index, ...);
void list_delete(List this, int index);
void list_insert(List this, int index, ...);
void *list_pick(List this, int index);
void list_foreach(List this, void(*function)(void*));

//array list
ArrayList new_array_list(Type type, int capacity);
void array_list_set(ArrayList list, int index, ...);
void array_list_print(ArrayList list);
void array_list_toString(ArrayList list, void(*function)(void*));
void array_list_free(ArrayList list);
void* array_list_get(ArrayList list, int index);

//iterator
void* iterator_next(TIterator iterator);
bool iterator_has_next(TIterator iterator);
void iterator_free(TIterator iterator);

#endif
