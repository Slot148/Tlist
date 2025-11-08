#include "Tlist.h"
#include <stdio.h>

typedef struct Pessoa{
    char nome[20];
    int idade;
} Pessoa;

// ✅ Assinatura correta - recebe void*
void print_pessoa(void *p){
    Pessoa *pessoa = (Pessoa*)p;
    printf("{Nome: %s, Idade: %d}", pessoa->nome, pessoa->idade);
}

int main(){
    printf("=== Testing Array List with Custom Type ===\n");
    
    ArrayList list = new_array_list(T, 10);
    Pessoa nicolas = {"Nicolas", 19};
    Pessoa maria = {"Maria", 25};
    
    // ✅ Set diferentes índices
    array_list_set(list, 0, &nicolas);
    array_list_set(list, 2, &maria);
    
    // ✅ Configura função de formatação
    array_list_toString(list, print_pessoa);
    
    printf("Array list with custom formatting: ");
    array_list_print(list);
    
    // ✅ Teste sem formatação personalizada
    printf("Array list without formatting: ");
    array_list_toString(list, NULL);  // Remove formatação
    array_list_print(list);
    
    array_list_free(list);
    
    printf("✅ Test completed successfully!\n");
    return 0;
}