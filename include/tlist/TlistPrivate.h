#ifndef T_LIST_PRIVATE
#define T_LIST_PRIVATE

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "Tlist.h"

struct Node{
    void *_val;      
    Node _nextNode;  
};

struct TIterator{
    Node _current;   
    List _list;      
    int _index;     
};

struct List{
    Node _head;    
    Node _tail;     
    Type _type;
    size_t _size;
    int _length;
};

struct ArrayList{
    void** _array;
    int _capacity;
    Type _type;
    size_t _size;
    int _length;
    void(*to_string)(void*);
    void(*clear_function)(void*);
};

/** @private */
Node _new_node(void *val, size_t size, Type type);
void _under_push(List this, Node node);
void _under_insert(List this, int index, Node node);
void* _clone_value(Node node, Type type);

#endif

