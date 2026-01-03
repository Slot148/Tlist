#include "Tlist.h"
#include "TlistPrivate.h"

ArrayList new_array_list(Type type, int capacity){
    ArrayList list = (ArrayList)malloc(sizeof(struct ArrayList));
    if(list == NULL) {
        fprintf(stderr, "Error in new_array_list(): Failed to allocate memory for the new list.\n");
        exit(EXIT_FAILURE);
    }
    list->_array = (void **)malloc(capacity * sizeof(void *));
        if (list->_array == NULL) {
        fprintf(stderr, "Error in new_array_list(): Failed to allocate memory for the array.\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->_capacity = capacity;
    list->_length = 0;
    list->_type = type;
    list->to_string = NULL;

    switch(type){
        case INT: list->_size = sizeof(int); break;
        case STRING: list->_size = sizeof(char *); break;
        case DOUBLE: list->_size = sizeof(double); break;
        case FLOAT: list->_size = sizeof(float); break;
        case T: list->_size = sizeof(void *); break;
    }

    for(int i = 0; i < capacity; i++){
        list->_array[i] = NULL;
    }

    return list;
}

void array_list_set(ArrayList list, int index, ...){
    if (list == NULL) {
        fprintf(stderr, "Error in array_list_set(): The provided list instance is NULL.\n");
        return;
    }
    if (index < 0 || index >= list->_capacity) {
        fprintf(stderr, "Error in array_list_set(): Index %d is out of bounds. Valid range is 0 to %d.\n", index, list->_capacity - 1);
        return;
    }
    va_list args;
    va_start(args, index);

    if (list->_array[index] != NULL && list->_type != T) {
        free(list->_array[index]);
    }

    switch (list->_type){
        case INT:{
            list->_array[index] = malloc(sizeof(int));
            *(int*)list->_array[index] = va_arg(args, int);
            break;
        }
        case STRING:{
            char* str = va_arg(args, char *);
            list->_array[index] = malloc(strlen(str) + 1);
            strcpy((char *)list->_array[index], str);
            break;
        }
        case DOUBLE:{
            list->_array[index] = malloc(sizeof(double));
            *(double*)list->_array[index] = va_arg(args, double);
            break;
        }
        case FLOAT:{
            list->_array[index] = malloc(sizeof(float));
            *(float*)list->_array[index] = (float)va_arg(args, double);
            break;
        }
        default:{
            list->_array[index] = va_arg(args, void *);
            break;
        }
    }

    if (index >= list->_length) {
        list->_length = index + 1;
    }
    
    va_end(args);
} 

void array_list_print(ArrayList list) {
    printf("[");
    for (int i = 0; i < list->_length; i++) {
        if (list->_array[i] != NULL) { 
            if(list->to_string == NULL){
                switch (list->_type) {
                    case INT: printf("%d", *(int *)list->_array[i]); break;
                    case STRING: printf("\"%s\"", (char *)list->_array[i]); break;
                    case DOUBLE: printf("%.2f", *(double *)list->_array[i]); break;
                    case FLOAT: printf("%.2f", *(float *)list->_array[i]); break;
                    case T: printf("%p", list->_array[i]); break;
                }
            }else{
                list->to_string(list->_array[i]);
            }
            
        } else {
            printf("NULL");
        }   
        if (i < list->_length - 1) printf(", ");
    }
    printf("]\n");
}

void array_list_toString(ArrayList list, void(*function)(void*)){
    list->to_string = function;
}

void array_list_free(ArrayList list){
    if (list == NULL) return;
    
    for (int i = 0; i < list->_length; i++) {
        if (list->_array[i] != NULL && list->_type != T){
            free(list->_array[i]);
        }
    }
    free(list->_array);
    free(list);
}

void* array_list_get(ArrayList list, int index){
    if (list == NULL) {
        fprintf(stderr, "Error in array_list_get(): The provided list instance is NULL.\n");
        return NULL;
    }
    if (index < 0 || index >= list->_length) {
        fprintf(stderr, "Error in array_list_get(): Index %d is out of bounds. Valid range is 0 to %d.\n", index, list->_length - 1);
        return NULL;
    }
    return list->_array[index];
}

void array_list_push_back(ArrayList list, ...){
    if (list == NULL) {
        fprintf(stderr, "Error in array_list_push_back(): The provided list instance is NULL.\n");
        return;
    }
}

void array_list_resize(ArrayList list){
    if (list == NULL) {
        fprintf(stderr, "Error in array_list_resize(): The provided list instance is NULL.\n");
        return;
    }   
}

// void array_list_clear(ArrayList list){

// }

// ArrayList array_list_clone(ArrayList list){

// }

// int array_list_contains(ArrayList list, ...){
    
// }