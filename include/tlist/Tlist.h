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

//linked list
List new_list(Type type);
List list_duplicate(const List this);
void list_print(List this);
int list_length(List this);
void list_free(List this);
void list_push(List this, ...);
void *list_pop(List this);
void *list_get(List this, int index);
void list_set(List this, int index, ...);
void list_delete(List this, int index);
void list_insert(List this, int index, ...);
void *list_pick(List this, int index);
void list_foreach(List this, void(*function)(void*));
void list_set_toString(List this, void(*function)(void*));
void list_set_clearFunction(List this, void(*function)(void*));

//array list
ArrayList new_array(Type type, int capacity);
ArrayList array_duplicate(ArrayList list);
void array_print(ArrayList list);
int array_length(ArrayList list);
void array_free(ArrayList list);
void* array_get(ArrayList list, int index);
void array_set(ArrayList list, int index, ...);
void array_clear(ArrayList list);
void array_resize(ArrayList list, int new_size);
void array_push_back(ArrayList list, ...);
void array_set_toString(ArrayList list, void(*function)(void*));
void array_set_clearFunction(ArrayList list, void(*function)(void*));


//iterator
TIterator new_iterator(List list);
void* iterator_next(TIterator iterator);
bool iterator_has_next(TIterator iterator);
void iterator_free(TIterator iterator);

#endif
