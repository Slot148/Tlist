#include "tlist/Tlist.h"
#include "tlist/TlistPrivate.h"

TIterator new_iterator(const List list){
    TIterator iterator = malloc(sizeof(struct TIterator));
    if(iterator == NULL) {
        fprintf(stderr, "Error in newIterator(): Failed to allocate memory for the new iterator.\n");
        exit(EXIT_FAILURE);
    }
    if (list == NULL) {
        fprintf(stderr, "Error in newIterator(): The provided list instance is NULL.\n");
        exit(EXIT_FAILURE);
    }
    iterator->_list = list;
    iterator->_current = list->_head;
    iterator->_index = 0;
    return iterator;
}

void* iterator_next(TIterator iterator){
    if (iterator == NULL || iterator->_current == NULL) {
        fprintf(stderr, "Error in next(): No more elements to iterate or invalid iterator.\n");
        return NULL;
    }
    void* val = iterator->_current->_val;
    iterator->_index++;
    iterator->_current = iterator->_current->_nextNode;
    return val;
}

bool iterator_has_next(TIterator iterator){
    if (iterator == NULL) {
        return false;
    }
    return iterator->_current != NULL;
}

void iterator_free(TIterator iterator){
    free(iterator);
}

void iterator_reset(TIterator iterator){
    iterator->_current = iterator->_list->_head;
    iterator->_index = 0;
}